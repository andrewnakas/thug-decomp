typedef int qword __attribute__((mode(TI)));
union Row_00287160 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Mat_00287160 {
    Row_00287160 r[4];
    Mat_00287160* Self() { return this; }
    void InvertOrtho()
    {
        Row_00287160 t = r[3];
        float d0 = t.f.x * r[0].f.x + t.f.y * r[0].f.y + t.f.z * r[0].f.z;
        float d1 = t.f.x * r[1].f.x + t.f.y * r[1].f.y + t.f.z * r[1].f.z;
        float d2 = t.f.x * r[2].f.x + t.f.y * r[2].f.y + t.f.z * r[2].f.z;
        float tmp;
        tmp = r[0].f.y; r[0].f.y = r[1].f.x; r[1].f.x = tmp;
        tmp = r[0].f.z; r[0].f.z = r[2].f.x; r[2].f.x = tmp;
        tmp = r[1].f.z; r[1].f.z = r[2].f.y; r[2].f.y = tmp;
        r[3].f.x = -d0;
        r[3].f.y = -d1;
        r[3].f.z = -d2;
    }
};
extern "C" void func_00323318(Mat_00287160* a, Mat_00287160* b, Mat_00287160* out);
extern "C" void func_00103930(void* q, Mat_00287160* out, float t);

struct Body_00287160 {
    char pad[0x70];
    Mat_00287160 m70;
    void GetMatrix(Mat_00287160* out) { *out = m70; }
};
struct Sub_00287160 {
    char pad[0xAC];
    int mAC;
};

static inline float Min_00287160(float a, float b)
{
    if (b < a)
        return b;
    return a;
}

struct Obj_00287160 {
    char pad0[0xC];
    Body_00287160* mC;
    char pad10[0x10];
    Mat_00287160 m20;
    char pad60[0x94 - 0x60];
    float m94;
    char pad98[0x480 - 0x98];
    char m480[0x520 - 0x480];
    float m520;
    float m524;
    char pad528[0x540 - 0x528];
    Mat_00287160 m540;
    char pad580[0x5B0 - 0x580];
    Sub_00287160* m5B0;
    void Blend();
};

void Obj_00287160::Blend()
{
    if (!m5B0->mAC) return;
    char* q = m480;
    float x = m520 + m94;
    m520 = x;
    float f = Min_00287160(x / m524, 1.0f);
    Mat_00287160 out;
    Mat_00287160* last = m540.Self();
    func_00103930(q, &out, f * -2.0f * f * (f - 1.5f));
    Mat_00287160 inv = m540;
    inv.InvertOrtho();
    Mat_00287160 tm;
    Mat_00287160 r;
    Mat_00287160* p = r.Self();
    *p = inv;
    func_00323318(p, &out, p);
    tm = r;
    func_00323318(&mC->m70, &tm, &mC->m70);
    mC->GetMatrix(&m20);
    *last = out;
}
