/* sym: __13Coll_001C85E8 = 0x00209240 */
/* sym: __12Box_001C85E8RC12Vec_001C85E8T1 = 0x00102340 */
typedef int qword __attribute__((mode(TI)));
union Vec_001C85E8;
extern "C" void func_003233B8(Vec_001C85E8* out, Vec_001C85E8* in);
union Vec_001C85E8 {
    qword q;
    float c[4];
    Vec_001C85E8() {}
    Vec_001C85E8(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    float& operator[](int i) { return c[i]; }
    void operator+=(const Vec_001C85E8& b)
    {
        c[0] += b.c[0];
        c[1] += b.c[1];
        c[2] += b.c[2];
        c[3] += b.c[3];
    }
    float operator[](int i) const { return c[i]; }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void Normalize() { func_003233B8(this, this); }
    void Flip()
    {
        c[0] = -c[0];
        c[1] = -c[1];
        c[2] = -c[2];
    }
};

extern "C" float fabsf(float);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
static inline float Param_001C85E8(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_001C85E8;
extern "C" Coll_001C85E8* func_00209240(Coll_001C85E8* c);
extern "C" int func_002093E8(Coll_001C85E8* c, int a, int b);
struct Coll_001C85E8 {
    Vec_001C85E8 m0;
    Vec_001C85E8 m10;
    char pad20[0xC0 - 0x20];
    struct Ref {
        void* p;
        void Release()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char padC4[0xD4 - 0xC4];
    void* mD4;
    char padD8[0xE0 - 0xD8];
    Coll_001C85E8();
};

struct Box_001C85E8;
extern "C" void func_00102340(Box_001C85E8* b, const Vec_001C85E8* lo, const Vec_001C85E8* hi);
struct Box_001C85E8 {
    char pad[0x20];
    Box_001C85E8(const Vec_001C85E8& lo, const Vec_001C85E8& hi);
};
extern "C" void* func_001DAD40();
extern "C" void func_001DA948(void* s, Box_001C85E8* b);
extern "C" void func_001DADB0(void* s);
extern "C" float func_00341068(float);

static inline void Add_001C85E8(Vec_001C85E8& r, const Vec_001C85E8& a, const Vec_001C85E8& b)
{
    r.c[0] = a[0] + b[0];
    r.c[1] = a[1] + b[1];
    r.c[2] = a[2] + b[2];
    r.c[3] = a[3] + b[3];
}
static inline void Sub_001C85E8(Vec_001C85E8& r, const Vec_001C85E8& a, const Vec_001C85E8& b)
{
    r.c[0] = a[0] - b[0];
    r.c[1] = a[1] - b[1];
    r.c[2] = a[2] - b[2];
    r.c[3] = a[3] - b[3];
}
static inline Vec_001C85E8 operator+(const Vec_001C85E8& a, const Vec_001C85E8& b)
{
    return Vec_001C85E8(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
static inline Vec_001C85E8 operator-(const Vec_001C85E8& a, const Vec_001C85E8& b)
{
    return Vec_001C85E8(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
static inline Vec_001C85E8 operator*(const Vec_001C85E8& a, float k)
{
    return Vec_001C85E8(a[0] * k, a[1] * k, a[2] * k, a[3] * k);
}
static inline void Mul_001C85E8(Vec_001C85E8& r, const Vec_001C85E8& a, float k)
{
    r.c[0] = a[0] * k;
    r.c[1] = a[1] * k;
    r.c[2] = a[2] * k;
    r.c[3] = a[3] * k;
}

static inline float Dot_001C85E8(const Vec_001C85E8& a, const Vec_001C85E8& b)
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

struct Surf_001C85E8 {
    char pad[0x58];
    unsigned int m58;
};

struct Hit_001C85E8 {
    Vec_001C85E8 m0;
    Vec_001C85E8 m10;
    float m20;
    float m24;
    float m28;
    unsigned int m2C;
    Surf_001C85E8* m30;
};

struct Obj_001C85E8 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x60 - 0x20];
    Vec_001C85E8 m60;
    int Find(Vec_001C85E8* a, Vec_001C85E8* b, Vec_001C85E8* pos, Vec_001C85E8* ref, Hit_001C85E8* out, float dist,
             int back);
};

extern "C" int func_001C8CC8(Obj_001C85E8* o, Coll_001C85E8* c, Vec_001C85E8* pos, Hit_001C85E8* out);

int Obj_001C85E8::Find(Vec_001C85E8* a, Vec_001C85E8* b, Vec_001C85E8* pos, Vec_001C85E8* ref, Hit_001C85E8* out,
                       float dist, int back)
{
    float h = Param_001C85E8(0xA8C13E74);
    if (m1C == 1) {
        if ((*ref)[1] < (*pos)[1])
            return 0;
        if (12.0f < fabsf((*pos)[1] - (*ref)[1]))
            return 0;
    }
    Vec_001C85E8 d;
    Sub_001C85E8(d, *b, *a);
    Vec_001C85E8 n = d;
    n.Normalize();
    float ay = fabsf(n[1]);
    if (func_00341068(Param_001C85E8(0x98724EBC) * 0.017453294f) < ay)
        return 0;
    out->m10.Set(-d[2], 0.0f, d[0], 1.0f);
    out->m10.Normalize();
    if (!back) {
        if (Dot_001C85E8(out->m10, m60) < 0.0f) {
            out->m10.Flip();
        }
    } else {
        if (0.0f < Dot_001C85E8(out->m10, m60)) {
            out->m10.Flip();
        }
    }
    bool left = 0.0f < out->m10[2] * n[0] - out->m10[0] * n[2];
    unsigned int fl = out->m30->m58;
    if (((fl & 0x80) && left) || ((fl & 0x40) && !left)) {
        out->m10.Flip();
        left = !left;
    }
    Coll_001C85E8 c;
    void* s = func_001DAD40();
    Box_001C85E8 box(*pos - Vec_001C85E8(24.0f, 24.0f, 24.0f, 1.0f), *pos + Vec_001C85E8(24.0f, h + 12.0f, 24.0f, 1.0f));
    func_001DA948(s, &box);
    out->m20 = dist;
    c.mD4 = s;
    if (func_001C8CC8(this, &c, pos, out))
        goto hit;
    if (m1C == 1 || !back) {
        fl = out->m30->m58;
        if (!(((fl & 0x80) && !left) || ((fl & 0x40) && left))) {
            out->m10.Flip();
            if (func_001C8CC8(this, &c, pos, out))
                goto hit;
        }
    }
    func_001DADB0(s);
    {
        Coll_001C85E8::Ref* r = &c.mC0;
        r->Release();
    }
    return 0;
hit:
    {
        out->m28 = out->m0[1] - (*pos)[1];
        out->m24 = Dot_001C85E8(out->m10, out->m0 - *pos);
        c.m0 = out->m0 + out->m10 * Param_001C85E8(0xC3263E6E);
        c.m0.c[1] += Param_001C85E8(0xDBB3D53E);
        c.m10 = c.m0;
        c.m10 += out->m10 * Param_001C85E8(0x2F83AE83);
        if (func_002093E8(&c, 1, 0))
            out->m2C = 0xEC0A1009;
        else
            out->m2C = 0x1EE948A5;
    }
    func_001DADB0(s);
    {
        Coll_001C85E8::Ref* r = &c.mC0;
        r->Release();
    }
    return 1;
}
