/* fuzzy: 98.8 */
extern "C" float sqrtf(float);
typedef int qword __attribute__((mode(TI)));
union Vec_001C0F20 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    const float& operator[](int i) const { return c[i]; }
    Vec_001C0F20() {}
    Vec_001C0F20(float x, float y, float z, float w)
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
    bool operator==(const Vec_001C0F20& o) const
    {
        bool r = false;
        if (c[0] == o[0] && c[1] == o[1] && c[2] == o[2] && c[3] == o[3]) r = true;
        return r;
    }
    float Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
    void operator-=(const Vec_001C0F20& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
};
inline Vec_001C0F20 operator*(const Vec_001C0F20& a, float k) { return Vec_001C0F20(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_001C0F20 operator+(const Vec_001C0F20& a, const Vec_001C0F20& b)
{
    return Vec_001C0F20(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_001C0F20 operator-(const Vec_001C0F20& a, const Vec_001C0F20& b)
{
    return Vec_001C0F20(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_001C0F20;
extern "C" Coll_001C0F20* func_00209240(Coll_001C0F20* c);
extern "C" int func_002093E8(Coll_001C0F20* c, int a, int b);
struct Coll_001C0F20 {
    Vec_001C0F20 start;
    Vec_001C0F20 end;
    char pad20[0x68 - 0x20];
    unsigned short m68;
    char pad6A[0x70 - 0x6A];
    int m70;
    char pad74[0x90 - 0x74];
    float m90;
    char pad94[0xA0 - 0x94];
    Vec_001C0F20 hit;
    Vec_001C0F20 normal;
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
    Coll_001C0F20() { func_00209240(this); }
    ~Coll_001C0F20() { mC0.Release(); }
};

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" unsigned int func_0010FC30();
struct Body_001C0F20 {
    char pad0[0xB0];
    Vec_001C0F20 mB0;
};
struct Handle_001C0F20 {
    Body_001C0F20* m0;
};
struct Rec_001C0F20 {
    char pad0[0x1C];
    Handle_001C0F20* m1C;
    unsigned int m20;
    bool Valid()
    {
        Handle_001C0F20* h = m1C;
        if (!h) return false;
        if (h->m0) return true;
        func_0010A8D8(D_00388A70, h);
        m1C = 0;
        m20 = func_0010FC30();
        return false;
    }
};
struct Flag_001C0F20 {
    char pad0[0x2C];
    int m2C;
};
struct Obj_001C0F20;
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" void func_001BF130(Obj_001C0F20* o, int state);
extern "C" int func_0019C9D8(void* p, Coll_001C0F20* c);
extern "C" void func_001BB080(void* p, int a, void* b);
extern "C" void func_001CE768(Rec_001C0F20* r, Coll_001C0F20* c);
extern "C" void func_0026FDD0(void* p);
extern "C" Vec_001C0F20* func_001016A8(Vec_001C0F20* v, const Vec_001C0F20* n);
extern "C" Vec_001C0F20* func_00101890(Vec_001C0F20* v, const Vec_001C0F20* n);

extern "C" int func_001C4780(Obj_001C0F20* o);
extern "C" int func_001CB9C8(Obj_001C0F20* o);
extern "C" int func_001C6C18(Obj_001C0F20* o);
extern "C" void func_001C4030(Obj_001C0F20* o, Vec_001C0F20* a, Vec_001C0F20* b);
extern "C" void func_001848F0(void* obj, unsigned int name, int a);
extern "C" void func_00184920(void* obj, unsigned int name, int a, float f);
extern "C" float fabsf(float);

static inline float Param_001C0F20(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

struct Cfg_001C0F20 {
    char pad0[0x1DC];
    int m1DC;
};

struct Surf_001C0F20 {
    char pad0[0x70];
    int m70;
    char pad74[0xE0 - 0x74];
};

struct Obj_001C0F20 {
    char pad0[0xC];
    void* mC;
    char pad10[0x30 - 0x10];
    Vec_001C0F20 m30;
    Vec_001C0F20 m40;
    Vec_001C0F20 m50;
    Vec_001C0F20 m60;
    Vec_001C0F20 m70;
    Vec_001C0F20 m80;
    unsigned int m90;
    char pad94[0x960 - 0x94];
    float m960;
    char pad964[0xA28 - 0x964];
    Cfg_001C0F20* mA28;
    char padA2C[0xA34 - 0xA2C];
    void* mA34;
    Flag_001C0F20* mA38;
    Rec_001C0F20* mA3C;
    char padA40[0xA50 - 0xA40];
    Vec_001C0F20 mA50;
    char padA60[0xA70 - 0xA60];
    Surf_001C0F20 mA70;
    int mB50;
    char padB54[0xB70 - 0xB54];
    Vec_001C0F20 mB70;
    void Ground();
};

void Obj_001C0F20::Ground()
{
    Coll_001C0F20 c;
    c.start = m30;
    c.start[1] += Param_001C0F20(0xCEE3A3E1);
    c.end = m30;
    c.end[1] -= Param_001C0F20(0xAF3E4251);
    if (!func_002093E8(&c, 1, 0) || (c.m68 & 2)) {
        if (func_002093E8(&c, 1, 0)) {
            m30 = c.hit + c.normal * 0.1f;
        }
        if (mB50) {
            func_001BB080(mA34, 1, &mA70);
            if (mA38->m2C) return;
        }
        if (mA28->m1DC) {
            if (m30 == m80) {
                m80[1] += 0.001f;
            }
            if (func_001C4780(this)) return;
        }
        if (func_001CB9C8(this)) return;
        if (func_001C6C18(this)) return;
        func_001BF130(this, 1);
        mB70 = m60;
        func_001C4030(this, &m40, &m50);
        m90 = 0xABF1F6AC;
        func_00184920(mC, 0xD96F01F1, 0, 0.0f);
    } else {
        float dy = c.hit[1] - m30[1];
        float ady = fabsf(dy);
        if (Param_001C0F20(0xD3193D8E) < ady) {
            void* obj = mC;
            func_001848F0(obj, 0.0f < dy ? 0x93FCF3ED : 0x56E21153, 0);
        }
        m30[1] = c.hit[1];
        if (0.0f < dy || dy < -3.0f) {
            float v = m960 - dy;
            if (v < 0.0f) v = 0.0f;
            m960 = v;
        }
        Surf_001C0F20* surf = &mA70;
        if (surf->m70 != c.m70) {
            if (mB50) {
                func_001BB080(mA34, 4, &mA70);
                if (mA38->m2C) return;
            }
            func_001BB080(mA34, 5, &c);
            if (mA38->m2C) return;
        }
        func_0019C9D8(&mA70, &c);
        mB50 = 1;
        mA50 = c.normal;
        func_001CE768(mA3C, &c);
    }
}
