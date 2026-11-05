typedef int qword __attribute__((mode(TI)));
extern "C" float fabsf(float);

struct Vec_002725F8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_002725F8;
extern "C" void func_00323318(Mat_002725F8* d, const Mat_002725F8* a, Mat_002725F8* b);
extern "C" Mat_002725F8* func_00100A58(Mat_002725F8* out, int axis, float a);
extern "C" float func_0010FAB8();

struct Mat_002725F8 {
    Vec_002725F8 r[4];
    Mat_002725F8() {}
    const Vec_002725F8& operator[](int i) const { return r[i]; }
    Mat_002725F8(const Mat_002725F8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_002725F8& operator=(const Mat_002725F8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    Mat_002725F8 operator*(const Mat_002725F8& b) const;
};

inline Mat_002725F8 Mat_002725F8::operator*(const Mat_002725F8& b) const
{
    Mat_002725F8 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

struct Body_002725F8 {
    char pad[0x70];
    Mat_002725F8 m70;
};

struct Node_002725F8 {
    char pad[0x20];
    Mat_002725F8 m20;
};

struct Axis_002725F8 {
    float target;
    float m4;
    float speed;
    float current;
    int active;
};

struct Base_002725F8 {
    int m0;
    int m4;
    int m8;
    Body_002725F8* mC;
    int m10;
    int m14;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6(int a);
};

struct Rot_002725F8 : Base_002725F8 {
    Axis_002725F8 m_axes[3];
    Node_002725F8* m58;
    void Update();
};

void Rot_002725F8::Update()
{
    for (int i = 0; i < 3; i++) {
        Axis_002725F8* a = &m_axes[i];
        if (a->active) {
            float step = func_0010FAB8() * a->speed;
            a->current += fabsf(step);
            if (a->target <= a->current) {
                float sign = 1.0f;
                a->active = 0;
                if (step < 0.0f) sign = -1.0f;
                step -= sign * (a->current - a->target);
            }
            Mat_002725F8 r;
            func_00100A58(&r, i, step);
            Mat_002725F8& m = mC->m70;
            m = r * m;
            m58->m20 = r * m58->m20;
        }
    }
    if (!m_axes[0].active && !m_axes[1].active && !m_axes[2].active) V6(1);
}
