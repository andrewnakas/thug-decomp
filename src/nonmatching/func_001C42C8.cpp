/* fuzzy: 85.0 */
typedef int qword __attribute__((mode(TI)));

extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);

struct Vec_001C42C8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001C42C8() {}
    Vec_001C42C8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void RotateY(float a)
    {
        float s = func_00341068(a);
        float c = func_00340F60(a);
        float nx = c * x + s * z;
        float nz = -s * x + c * z;
        x = nx;
        z = nz;
    }
    Vec_001C42C8& operator=(const Vec_001C42C8& o)
    {
        q = o.q;
        return *this;
    }
};

struct Mat_001C42C8 {
    float m[16];
};

struct Res_001C42C8 {
    void* h;
    char pad4[0x60 - 4];
    Vec_001C42C8 m60;
    Mat_001C42C8 m70;
    int mB0;
    void Offset(Vec_001C42C8& v) { v.x += m60.x; v.y += m60.y; v.z += m60.z; v.w += m60.w; }
};

extern void* D_00388A70;
extern "C" unsigned int func_0010FC30();
extern "C" void func_00183CB8(void*, void*);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" int func_0020A760(Res_001C42C8* r, Vec_001C42C8* pos);
extern "C" void func_003233B8(Vec_001C42C8* dst, Vec_001C42C8* src);
extern "C" void func_001A0E50(void* o, float* a, float* b, float* c);

static inline void Free_001C42C8(Res_001C42C8* r)
{
    if (r->h) {
        func_00183CB8(r->h, r);
        r->h = 0;
    }
    func_0010A8D8(D_00388A70, r);
}

struct Holder_001C42C8 {
    char pad[0x1C];
    Res_001C42C8* m1C;
    unsigned int m20;
    bool Valid()
    {
        if (!m1C) return false;
        if (m1C->h) return true;
        func_0010A8D8(D_00388A70, m1C);
        m1C = 0;
        m20 = func_0010FC30();
        return false;
    }
    void Release()
    {
        Res_001C42C8* r = m1C;
        if (r) {
            Free_001C42C8(r);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
    bool Update(Vec_001C42C8* pos)
    {
        if (!Valid()) return false;
        if (func_0020A760(m1C, pos)) return true;
        Release();
        return false;
    }
};

static inline float Clamp_001C42C8(float v)
{
    if (v > 1.0f) {
        v = 1.0f;
    }
    return v;
}

struct Obj_001C42C8 {
    char pad0[0x30];
    Vec_001C42C8 m30;
    char pad40[0x20];
    Vec_001C42C8 m60;
    char pad70[0x20];
    unsigned int m90;
    char pad94[0x30];
    float mC4;
    char padC8[0xA2C - 0xC8];
    void* mA2C;
    char padA30[0xA3C - 0xA30];
    Holder_001C42C8* mA3C;
    char padA40[0xC10 - 0xA40];
    Vec_001C42C8 mC10;
    char padC20[0x10];
    Vec_001C42C8 mC30;
    float mC40;
    float mC44;
    char padC48[8];
    Vec_001C42C8 mC50;
    float mC60;
    float mC64;
    char padC68[8];
    Vec_001C42C8 mC70;
    Vec_001C42C8 RotatedC50(const Mat_001C42C8& M)
    {
        Vec_001C42C8 t;
        t.x = mC50.x * M.m[0] + mC50.y * M.m[4] + mC50.z * M.m[8];
        t.y = mC50.x * M.m[1] + mC50.y * M.m[5] + mC50.z * M.m[9];
        t.z = mC50.x * M.m[2] + mC50.y * M.m[6] + mC50.z * M.m[10];
        t.w = mC50.w;
        return t;
    }
    void Follow();
};

void Obj_001C42C8::Follow()
{
    Holder_001C42C8* h = mA3C;
    if (h->Update(&m30)) {
        mA3C->m1C->Offset(mC70);
        if (mA3C->m1C->mB0) {
            mC50 = RotatedC50(mA3C->m1C->m70);
            if (mC50.y != 0.0f) {
                mC50.y = 0.0f;
                func_003233B8(&mC50, &mC50);
            }
        }
    }
    float a;
    float b;
    float c;
    func_001A0E50(mA2C, &a, &b, &c);
    float t = (b - a) / (c - a);
    Vec_001C42C8 r;
    Vec_001C42C8 l;
    Vec_001C42C8 dt;
    Vec_001C42C8 d;
    d.x = mC30.x - mC10.x;
    d.y = mC30.y - mC10.y;
    d.z = mC30.z - mC10.z;
    d.w = mC30.w - mC10.w;
    dt.x = d.x * t;
    dt.y = d.y * t;
    dt.z = d.z * t;
    dt.w = d.w * t;
    l.x = mC10.x + dt.x;
    l.y = mC10.y + dt.y;
    l.z = mC10.z + dt.z;
    l.w = mC10.w + dt.w;
    r.x = mC70.x + l.x;
    r.y = mC70.y + l.y;
    r.z = mC70.z + l.z;
    r.w = mC70.w + l.w;
    m30 = r;
    float k = t / mC60;
    float n = -mC64;
    if (k > 1.0f) {
        k = 1.0f;
    }
    float ang = n + mC64 * k;
    m60 = mC50;
    m60.RotateY(ang);
    m90 = 0x4FE6069C;
    mC4 = mC40 + (mC44 - mC40) * t;
}
