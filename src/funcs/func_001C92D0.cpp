typedef int qword __attribute__((mode(TI)));
union Vec_001C92D0 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_001C92D0() {}
    Vec_001C92D0(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
};
inline Vec_001C92D0 operator*(const Vec_001C92D0& a, float k) { return Vec_001C92D0(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_001C92D0 operator+(const Vec_001C92D0& a, const Vec_001C92D0& b)
{
    return Vec_001C92D0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
struct Mat_001C92D0 {
    Vec_001C92D0 r[4];
};

extern "C" float fabsf(float);
extern "C" float func_00340F60(float a);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
static inline float Param_001C92D0(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

extern "C" void func_00183CB8(void* p, void* pp);
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" unsigned int func_0010FC30();
struct Handle_001C92D0 {
    void* m0;
    void Release()
    {
        if (m0) {
            func_00183CB8(m0, this);
            m0 = 0;
        }
    }
};
extern "C" int func_0020A760(Handle_001C92D0* h, Vec_001C92D0* p);
struct Rec_001C92D0 {
    char pad0[0x1C];
    Handle_001C92D0* m1C;
    unsigned int m20;
    bool Valid()
    {
        Handle_001C92D0* h = m1C;
        if (!h) return false;
        if (h->m0) return true;
        func_0010A8D8(D_00388A70, h);
        m1C = 0;
        m20 = func_0010FC30();
        return false;
    }
    void Clear()
    {
        Handle_001C92D0* h = m1C;
        if (h) {
            h->Release();
            func_0010A8D8(D_00388A70, h);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
    bool Check(Vec_001C92D0* p)
    {
        if (!Valid()) return false;
        if (func_0020A760(m1C, p)) return true;
        Clear();
        return false;
    }
};

struct Sub_001C92D0 {
    char pad0[0x26C];
    float m26C;
    float m270;
    int m274;
    int m278;
};
struct Sk_001C92D0 {
    char pad0[0x24];
    Sub_001C92D0 m24;
};

struct Obj_001C92D0;
extern "C" void* func_00185578(void* o, unsigned int name);
extern "C" Mat_001C92D0 func_001B7750(void* o);
extern "C" void func_001CA978(Obj_001C92D0* o);
extern "C" int func_001CAFC0(Obj_001C92D0* o, Vec_001C92D0* p);
extern "C" void func_001BF130(Obj_001C92D0* o, int state);
extern "C" void func_001C4030(Obj_001C92D0* o, Vec_001C92D0* a, float* b);
extern "C" void func_001C97D8(Obj_001C92D0* o, float amount);

struct Obj_001C92D0 {
    char pad0[0x30];
    Vec_001C92D0 m30;
    Vec_001C92D0 m40;
    float m50;
    char pad54[0x60 - 0x54];
    Vec_001C92D0 m60;
    char pad70[0x90 - 0x70];
    unsigned int m90;
    char pad94[0x98 - 0x94];
    float m98;
    char pad9C[0xB0 - 0x9C];
    float mB0;
    int mB4;
    char padB8[0x954 - 0xB8];
    float m954;
    char pad958[0xA28 - 0x958];
    Sk_001C92D0* mA28;
    char padA2C[0xA3C - 0xA2C];
    Rec_001C92D0* mA3C;
    char padA40[0xB70 - 0xA40];
    Vec_001C92D0 mB70;
    char padB80[0xC00 - 0xB80];
    float mC00;
    void Rail();
};

void Obj_001C92D0::Rail()
{
    if (mA3C->Check(&m30)) {
        func_001B7750(func_00185578(mA3C->m1C->m0, 0x1CDFB2A3));
        func_001CA978(this);
    }
    if (mB4) {
        Sub_001C92D0* p = &mA28->m24;
        int a = 0;
        if (!p->m274 && p->m270 != 0.0f && fabsf(p->m26C) < 0.78539824f) a = 1;
        if (a) {
            Vec_001C92D0 v = m30 + m60 * Param_001C92D0(0x21DFBE77);
            v[1] += Param_001C92D0(0x52FA7CA6);
            if (func_001CAFC0(this, &v)) return;
            v = m30 + m60 * (Param_001C92D0(0x21DFBE77) * 0.5f);
            v[1] += Param_001C92D0(0x52FA7CA6);
            if (func_001CAFC0(this, &v)) return;
        } else {
            Sub_001C92D0* q = &mA28->m24;
            int b = 0;
            if (!q->m278 && q->m270 != 0.0f && 3.1415927f - fabsf(q->m26C) < 0.78539824f) b = 1;
            if (b) {
                func_001BF130(this, 1);
                mB70 = m60;
                func_001C4030(this, &m40, &m50);
                m90 = 0x439F4704;
                return;
            }
        }
    }
    float d = fabsf(1.5707964f - fabsf(mA28->m24.m26C));
    float t;
    if (d < func_00340F60(Param_001C92D0(0x1B877928) * 0.017453294f)) {
        float s = Param_001C92D0(0xD77EE881);
        float r = s * mB0;
        if (mA28->m24.m26C <= 0.0f) r = -r;
        t = r;
    } else
        t = 0.0f;
    mC00 = mC00 + (t - mC00) * (Param_001C92D0(0xC506A97C) * m98);
    float a = fabsf(mC00);
    if (Param_001C92D0(0x228B5376) < a) {
        m954 = fabsf(mC00);
        func_001C97D8(this, mC00 * m98);
        func_001CA978(this);
        return;
    }
    m90 = 0x4194ECCA;
}
