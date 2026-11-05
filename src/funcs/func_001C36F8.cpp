typedef int qword_001C36F8 __attribute__((mode(TI)));

struct Vec_001C36F8 {
    union {
        qword_001C36F8 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Mat_001C36F8 {
    Vec_001C36F8 row[4];
    const Vec_001C36F8& operator[](int i) const { return row[i]; }
    Mat_001C36F8& operator=(const Mat_001C36F8& o)
    {
        row[0] = o[0];
        row[1] = o[1];
        row[2] = o[2];
        row[3] = o[3];
        return *this;
    }
};

struct Body_001C36F8 {
    char pad0[0x70];
    Mat_001C36F8 m_mat;
    char padB0[0x10];
    Mat_001C36F8 m_lastMat;
};

extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int required);
extern "C" Mat_001C36F8* func_00100700(Mat_001C36F8* m, const Vec_001C36F8* axis, float angle);
extern "C" void func_00323318(Mat_001C36F8* d, const Mat_001C36F8* a, Mat_001C36F8* b);

static inline float Max_001C36F8(float a, float b)
{
    if (a < b)
        return b;
    return a;
}

struct Obj_001C36F8 {
    char pad0[0xC];
    Body_001C36F8* m_body;
    char pad10[0x88];
    float m_dt;
    char pad9C[0x8E4];
    float m_spinTime;
    float m_spinRate;
    char pad988[8];
    Vec_001C36F8 m_axis;

    void UpdateSpin();
};

void Obj_001C36F8::UpdateSpin()
{
    if (m_spinTime == 0.0f)
        return;
    float period;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0xB0675803, &period, 1);
    Mat_001C36F8 rot;
    Mat_001C36F8* m = &m_body->m_mat;
    func_00100700(&rot, &m_axis, m_spinRate * (m_dt / period));
    func_00323318(m, &rot, m);
    m_body->m_lastMat = m_body->m_mat;
    m_spinTime -= m_dt;
    m_spinTime = Max_001C36F8(m_spinTime, 0.0f);
}
