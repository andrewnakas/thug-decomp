typedef int qword __attribute__((mode(TI)));
union Vec_0028A718 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_0028A718() {}
    Vec_0028A718(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    float Length() const;
};
extern "C" float sqrtf(float);
extern "C" float fabsf(float);
inline float Vec_0028A718::Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
inline Vec_0028A718 operator-(const Vec_0028A718& a, const Vec_0028A718& b)
{
    return Vec_0028A718(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

struct Node_0028A718 {
    char pad0[0x50];
    Node_0028A718* m50;
    Node_0028A718* m54;
};
struct Glob_0028A718 {
    char pad0[0xAC];
    unsigned int mAC;
};
struct Body_0028A718 {
    char pad0[0xB4];
    float mB4;
};
extern "C" unsigned int func_0010FC30();
struct Timer_0028A718 {
    int m0;
    int m4;
    unsigned int m8;
    void Start()
    {
        if (m4 != 1) {
            m4 = 1;
            m8 = func_0010FC30();
        }
    }
};
static inline unsigned int Since_0028A718(unsigned int t) { return func_0010FC30() - t; }
struct Ctl_0028A718 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x4C - 0x20];
    int m4C;
    char pad50[0x6C - 0x50];
    Timer_0028A718 m6C;
    char pad78[0xF4 - 0x78];
    int mF4;
    char padF8[0x130 - 0xF8];
    int m130;
};
struct Rail_0028A718;
extern Glob_0028A718* D_00392808;
extern "C" Vec_0028A718 func_0026B1B0(Rail_0028A718* r, Node_0028A718* n);

struct Obj_0028A718 {
    char pad0[0xC];
    Body_0028A718* mC;
    char pad10[0x29C - 0x10];
    Node_0028A718* m29C;
    Rail_0028A718* m2A0;
    unsigned int m2A4;
    int pad2A8;
    unsigned int m2AC;
    char pad2B0[0x5B0 - 0x2B0];
    Ctl_0028A718* m5B0;
    bool Check(Node_0028A718* n, int unused, int force);
};

bool Obj_0028A718::Check(Node_0028A718* n, int unused, int force)
{
    if (m5B0->m1C == 1 && m5B0->mF4 && m5B0->m130 && (m29C == n || m29C == n->m50 || m29C == n->m54))
        return false;
    Node_0028A718* cur = m29C;
    if (!cur || (cur != n && cur != n->m50 && cur != n->m54)) {
        if (!cur || D_00392808->mAC == 0xD443A2BC) {
            m5B0->m6C.Start();
        } else {
            Vec_0028A718 d0 = func_0026B1B0(m2A0, cur) - func_0026B1B0(m2A0, n);
            Vec_0028A718 d1 = func_0026B1B0(m2A0, m29C) - func_0026B1B0(m2A0, n->m50);
            Vec_0028A718 d2 = func_0026B1B0(m2A0, m29C->m50) - func_0026B1B0(m2A0, n);
            Vec_0028A718 d3 = func_0026B1B0(m2A0, m29C->m50) - func_0026B1B0(m2A0, n->m50);
            if (6.0f < fabsf(d0.Length()) && 6.0f < fabsf(d1.Length()) && 6.0f < fabsf(d2.Length()) &&
                6.0f < fabsf(d3.Length()))
                m5B0->m6C.Start();
        }
    }
    bool r = false;
    if (m5B0->m6C.m4 || m2AC < Since_0028A718(m2A4)) {
        if (force || (m5B0->m1C != 4 && (!m5B0->m4C || 0.0f < mC->mB4)))
            r = true;
    }
    return r;
}
