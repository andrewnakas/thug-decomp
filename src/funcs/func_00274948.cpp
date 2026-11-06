/* sym: __15Feeler_00274948 = 0x00209240 */
typedef int qword_00274948 __attribute__((mode(TI)));
union Vec_00274948 {
    qword_00274948 q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_00274948() {}
    Vec_00274948(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    void operator+=(const Vec_00274948& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};
extern "C" float sqrtf(float);
inline Vec_00274948 operator*(const Vec_00274948& a, float k) { return Vec_00274948(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_00274948 operator+(const Vec_00274948& a, const Vec_00274948& b)
{
    return Vec_00274948(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_00274948 operator-(const Vec_00274948& a, const Vec_00274948& b)
{
    return Vec_00274948(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
inline float Dot_00274948(const Vec_00274948& a, const Vec_00274948& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }

extern "C" void func_00183CB8(void* obj, void* ref);
struct Ref_00274948 {
    void* m_obj;
    ~Ref_00274948()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};
struct Feeler_00274948 {
    Vec_00274948 m_start;
    Vec_00274948 m_end;
    char pad20[0x68 - 0x20];
    unsigned short m68;
    char pad6A[0xA0 - 0x6A];
    Vec_00274948 hit;
    Vec_00274948 normal;
    Ref_00274948 mC0;
    int mC4[7];
    Feeler_00274948();
};
struct Body_00274948 {
    char pad0[0x50];
    Vec_00274948 m50;
    char pad60[0x70 - 0x60];
    char m70[0x80 - 0x70];
    Vec_00274948 m80;
    Vec_00274948 m90;
};
extern "C" void func_00209380(Feeler_00274948* f, Vec_00274948* s, Vec_00274948* e);
extern "C" void func_00209350(Feeler_00274948* f, int a, int b);
extern "C" int func_002093E8(Feeler_00274948* f, int a, int b);
extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_00341068(float);
extern "C" float func_00340F60(float);
extern "C" float func_003412F0(float);
extern "C" float func_00341158(float);
extern "C" int func_00101730(Vec_00274948*, Vec_00274948*);
extern "C" void func_00100DC0(void* m, int a);

struct Obj_00274948 {
    char pad0[0xC];
    Body_00274948* mC;
    char pad10[0x50 - 0x10];
    Vec_00274948 m50;
    Vec_00274948 m60;
    void Run();
};

void Obj_00274948::Run()
{
    Vec_00274948 a;
    Vec_00274948 b;
    Feeler_00274948 f;
    int ok = 0;
    Body_00274948* o = mC;
    a = o->m80 * func_002032A0(0xE4D79235, 0);
    b = mC->m80 * -200.0f;
    a += mC->m50;
    b += mC->m50;
    func_00209380(&f, &a, &b);
    func_00209350(&f, 0x10, 0);
    if (func_002093E8(&f, 1, 0)) {
        Vec_00274948 d = mC->m50 - f.hit;
        float dist = sqrtf(Dot_00274948(d, d));
        float along = Dot_00274948(mC->m80, d);
        unsigned short fl = f.m68;
        if (fl == 0 || (fl & 6)
            || f.normal[1] < func_00341068(func_002032A0(0x3EEDE4D3, 0) * 0.01745329425f)) {
            if (along < 0.001f) {
                mC->m50 = f.hit + f.normal;
            }
        } else {
            Vec_00274948 n = f.normal;
            ok = 1;
            Vec_00274948 u = mC->m90;
            float d0 = Dot_00274948(u, n);
            Vec_00274948 w = u;
            func_00101730(&u, &n);
            func_00101730(&w, &m60);
            float d1 = Dot_00274948(u, w);
            float lim0 = func_00340F60(func_002032A0(0x4138283E, 0) * 0.01745329425f);
            if (0.0f < d0 && 0.0f < d1 && d1 < lim0) {
                ok = 0;
            } else {
                if (0.0f < along) {
                    float ang = func_003412F0(d1);
                    Vec_00274948 e = mC->m50 - m50;
                    float len = sqrtf(Dot_00274948(e, e));
                    float lim = len * func_00341158(ang);
                    float mn = func_002032A0(0x899BA3D0, 0);
                    if (lim < mn) lim = mn;
                    if (lim < dist) ok = 0;
                }
                if (ok) {
                    m60 = n;
                    mC->m80 = n;
                    func_00100DC0(mC->m70, 1);
                }
            }
        }
        if (ok) mC->m50 = f.hit;
    }
}
