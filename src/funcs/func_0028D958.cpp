typedef int qword __attribute__((mode(TI)));
union Vec_0028D958 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_0028D958() {}
    Vec_0028D958(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    float Length() const;
    void Normalize();
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
};
extern "C" float sqrtf(float);
inline float Vec_0028D958::Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
inline float Dot_0028D958(const Vec_0028D958& a, const Vec_0028D958& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
inline Vec_0028D958 operator*(const Vec_0028D958& a, float k) { return Vec_0028D958(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_0028D958 operator+(const Vec_0028D958& a, const Vec_0028D958& b)
{
    return Vec_0028D958(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_0028D958 operator-(const Vec_0028D958& a, const Vec_0028D958& b)
{
    return Vec_0028D958(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

struct Body_0028D958 {
    char pad0[0x50];
    Vec_0028D958 m50;
    char pad60[0x90 - 0x60];
    Vec_0028D958 m90;
    char padA0[0xB0 - 0xA0];
    Vec_0028D958 mB0;
};
struct Node_0028D958 {
    char pad0[0x50];
    Node_0028D958* m50;
    Node_0028D958* m54;
    char pad58[0x5E - 0x58];
    unsigned char m5E;
};
struct Glob_0028D958 {
    char pad0[0xAC];
    unsigned int mAC;
};
struct Info_0028D958 {
    char pad0[0x13C];
    int m13C;
};
struct Ctl_0028D958 {
    char pad0[0x20];
    int m20;
};
struct Rail_0028D958;
struct Obj_0028D958;
extern Glob_0028D958* D_00392808;


extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_00340F60(float);
extern "C" int func_002692B0(Node_0028D958* n, Vec_0028D958* v);
extern "C" int func_0026A270(Rail_0028D958* r, Vec_0028D958* a, Vec_0028D958* b, Vec_0028D958* out, Node_0028D958** node,
                             Node_0028D958* cur, float f, int k);
extern "C" Vec_0028D958 func_0026B1B0(Rail_0028D958* r, Node_0028D958* n);
extern "C" void func_003233B8(Vec_0028D958* a, Vec_0028D958* b);
inline void Vec_0028D958::Normalize() { func_003233B8(this, this); }
extern "C" Vec_0028D958* func_00101820(Vec_0028D958* a, const Vec_0028D958& b);
extern "C" void func_0028DF70(Obj_0028D958* o, int v);
extern "C" void func_0027C720(Obj_0028D958* o, int v);
extern "C" void func_001848F0(void*, unsigned int, int);

struct Obj_0028D958 {
    char pad0[0xC];
    Body_0028D958* mC;
    char pad10[0x94 - 0x10];
    float m94;
    char pad98[0x29C - 0x98];
    Node_0028D958* m29C;
    Rail_0028D958* m2A0;
    char pad2A4[0x59C - 0x2A4];
    Ctl_0028D958* m59C;
    char pad5A0[0x5B0 - 0x5A0];
    Info_0028D958* m5B0;
    void Snap(const Vec_0028D958& in);
};

void Obj_0028D958::Snap(const Vec_0028D958& in)
{
    bool fail = true;
    Vec_0028D958 pos;
    if (D_00392808->mAC != 0xD443A2BC) {
        pos = in;
    } else {
        pos = mC->m50 - mC->mB0 * m94;
    }
    Vec_0028D958 top = mC->m50;
    Vec_0028D958 np;
    pos[1] += 6.0f;
    top[1] = 6.1f + top[1];
    float k = func_00340F60(func_002032A0(0x76C1DA15, 0) * 0.017453294f);
    Node_0028D958* hit;
    if (func_0026A270(m2A0, &pos, &top, &np, &hit, m29C, k, func_002692B0(m29C, &mC->mB0))) {
        Node_0028D958* node = hit;
        if (m29C != node) {
            if (D_00392808->mAC == 0xD443A2BC || (m29C->m50 != node && m29C->m54 != node)) {
                Node_0028D958* next = node->m50;
                Vec_0028D958 d1 = func_0026B1B0(m2A0, node) - mC->m50;
                Vec_0028D958 d2 = func_0026B1B0(m2A0, next) - mC->m50;
                float dot = Dot_0028D958(d1, d2);
                int ok = dot < 0.0f;
                if (!ok && D_00392808->mAC != 0xD443A2BC) {
                    ok = 1;
                    Vec_0028D958 seg = func_0026B1B0(m2A0, next) - func_0026B1B0(m2A0, node);
                    Vec_0028D958 dp = top - pos;
                    if (seg.Length() > dp.Length()) ok = 0;
                    if (ok && 0.0f <= dot) {
                        np = (func_0026B1B0(m2A0, next) + func_0026B1B0(m2A0, node)) * 0.5f;
                    }
                }
                if (ok) {
                    Vec_0028D958 dir;
                    Vec_0028D958 a = func_0026B1B0(m2A0, next);
                    Vec_0028D958 b = func_0026B1B0(m2A0, node);
                    dir.c[0] = a.c[0] - b.c[0];
                    dir.c[1] = a.c[1] - b.c[1];
                    dir.c[2] = a.c[2] - b.c[2];
                    dir.c[3] = a.c[3] - b.c[3];
                    dir.Normalize();
                    if (mC->mB0[0] == 0.0f && mC->mB0[2] == 0.0f) {
                        mC->mB0[0] = mC->m90[0];
                        mC->mB0[2] = mC->m90[2];
                    }
                    float s = 1.0f;
                    if (Dot_0028D958(dir, mC->mB0) < 0.0f) s = -1.0f;
                    func_00101820(&mC->mB0, dir);
                    fail = false;
                    mC->mB0 *= s;
                    m29C = hit;
                    mC->m50 = np;
                    func_0028DF70(this, 5);
                    int id = m29C->m5E;
                    m5B0->m13C = id;
                    m59C->m20 = id;
                }
            }
        }
    }
    if (fail) {
        func_0028DF70(this, 4);
        func_0027C720(this, 1);
        mC->m50[1] += 1.0f;
        func_001848F0(mC, 0xAFAA46BA, 0);
    }
}
