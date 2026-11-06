extern "C" float sqrtf(float);
typedef int qword __attribute__((mode(TI)));
union Vec_001C2AB0 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_001C2AB0() {}
    Vec_001C2AB0(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    float Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
    void operator-=(const Vec_001C2AB0& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
};
inline Vec_001C2AB0 operator*(const Vec_001C2AB0& a, float k) { return Vec_001C2AB0(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_001C2AB0 operator+(const Vec_001C2AB0& a, const Vec_001C2AB0& b)
{
    return Vec_001C2AB0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_001C2AB0 operator-(const Vec_001C2AB0& a, const Vec_001C2AB0& b)
{
    return Vec_001C2AB0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_001C2AB0;
extern "C" Coll_001C2AB0* func_00209240(Coll_001C2AB0* c);
extern "C" int func_002093E8(Coll_001C2AB0* c, int a, int b);
struct Coll_001C2AB0 {
    Vec_001C2AB0 start;
    Vec_001C2AB0 end;
    char pad20[0x68 - 0x20];
    unsigned short m68;
    char pad6A[0x90 - 0x6A];
    float m90;
    char pad94[0xA0 - 0x94];
    Vec_001C2AB0 hit;
    Vec_001C2AB0 normal;
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
    char padC4[0xE0 - 0xC4];
    Coll_001C2AB0() { func_00209240(this); }
    ~Coll_001C2AB0() { mC0.Release(); }
};

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" unsigned int func_0010FC30();
struct Body_001C2AB0 {
    char pad0[0xB0];
    Vec_001C2AB0 mB0;
};
struct Handle_001C2AB0 {
    Body_001C2AB0* m0;
};
struct Rec_001C2AB0 {
    char pad0[0x1C];
    Handle_001C2AB0* m1C;
    unsigned int m20;
    bool Valid()
    {
        Handle_001C2AB0* h = m1C;
        if (!h) return false;
        if (h->m0) return true;
        func_0010A8D8(D_00388A70, h);
        m1C = 0;
        m20 = func_0010FC30();
        return false;
    }
};
struct Flag_001C2AB0 {
    char pad0[0x2C];
    int m2C;
};
struct Obj_001C2AB0;
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" void func_001BF130(Obj_001C2AB0* o, int state);
extern "C" int func_0019C9D8(void* p, Coll_001C2AB0* c);
extern "C" void func_001BB080(void* p, int a, void* b);
extern "C" void func_001CE768(Rec_001C2AB0* r, Coll_001C2AB0* c);
extern "C" void func_0026FDD0(void* p);
extern "C" Vec_001C2AB0* func_001016A8(Vec_001C2AB0* v, const Vec_001C2AB0* n);
extern "C" Vec_001C2AB0* func_00101890(Vec_001C2AB0* v, const Vec_001C2AB0* n);

struct Obj_001C2AB0 {
    char pad0[0x30];
    Vec_001C2AB0 m30;
    Vec_001C2AB0 m40;
    int m50;
    char pad54[0x60 - 0x54];
    Vec_001C2AB0 m60;
    char pad70[0x90 - 0x70];
    unsigned int m90;
    char pad94[0xB0 - 0x94];
    float mB0;
    char padB4[0x970 - 0xB4];
    Vec_001C2AB0 m970;
    char pad980[0xA28 - 0x980];
    char* mA28;
    char padA2C[0xA34 - 0xA2C];
    void* mA34;
    Flag_001C2AB0* mA38;
    Rec_001C2AB0* mA3C;
    char padA40[0xA50 - 0xA40];
    Vec_001C2AB0 mA50;
    char padA60[0xA70 - 0xA60];
    char mA70[0xB50 - 0xA70];
    int mB50;
    void Land(Vec_001C2AB0* a, Vec_001C2AB0* b);
};

void Obj_001C2AB0::Land(Vec_001C2AB0* a, Vec_001C2AB0* b)
{
    Coll_001C2AB0 c;
    c.start = *a;
    c.end = *b;
    if (!func_002093E8(&c, 1, 0)) return;
    if (c.m68 & 2) {
        m30 = c.hit + c.normal * 0.1f;
        float k = 1.0f - c.m90;
        Vec_001C2AB0 d = (c.end - c.start) * k;
        func_001016A8(&d, &c.normal);
        c.start = m30;
        c.end = m30 + d;
        if (func_002093E8(&c, 1, 0))
            m30 = c.hit + c.normal * 0.05f;
        else
            m30 = c.end;
        return;
    }
    m50 = 0;
    m30 = c.hit;
    func_001BF130(this, 0);
    func_0019C9D8(mA70, &c);
    mB50 = 1;
    func_001BB080(mA34, 3, mA70);
    if (mA38->m2C) return;
    mA50 = c.normal;
    func_001CE768(mA3C, &c);
    if (mA3C->Valid()) {
        m40 -= mA3C->m1C->m0->mB0;
        m40[1] = 0.0f;
    }
    if (m40[0] * m60[0] + m40[1] * m60[1] + m40[2] * m60[2] > 0.0f) {
        func_00101890(&m40, &m60);
        if (mB0 == 0.0f) {
            float len = m40.Length();
            float v;
            func_001E7EB0(func_001E5548(0x6775E538, 0), 0x530DCF34, &v, 1);
            if (len < v) goto reset;
        }
    } else {
    reset:
        m40.Set(0.0f, 0.0f, 0.0f, 1.0f);
    }
    m970.Set(0.0f, 0.0f, 0.0f, 1.0f);
    func_0026FDD0(mA28 + 0x1FC);
    m90 = 0x57FF2A27;
}
