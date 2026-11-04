typedef int qword __attribute__((mode(TI)));

struct Vec_001CB9C8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 1.0f; }
};

struct Res_001CB9C8 {
    void* h;
};

extern void* D_00388A70;
extern "C" unsigned int func_0010FC30();
extern "C" void func_00183CB8(void*, void*);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void* func_001E5548(unsigned int id, int flags);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);

struct Holder_001CB9C8 {
    char pad[0x1C];
    Res_001CB9C8* m1C;
    unsigned int m20;
    void Release()
    {
        Res_001CB9C8* r = m1C;
        if (r) {
            if (r->h) {
                func_00183CB8(r->h, r);
                r->h = 0;
            }
            func_0010A8D8(D_00388A70, r);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
};

struct Sk_001CB9C8 {
    char pad[0xA0];
    int mA0;
};

struct Ctl_001CB9C8 {
    char pad[0x5B0];
    Sk_001CB9C8* m5B0;
};

struct Glob_001CB9C8 {
    char pad[0x28];
    void* m28;
};

extern Glob_001CB9C8* D_0038FC78;

struct Obj_001CB9C8 {
    char pad0[0x30];
    Vec_001CB9C8 m30;
    Vec_001CB9C8 m40;
    int m50;
    char pad54[0x3C];
    unsigned int m90;
    char pad94[0x30];
    float mC4;
    char padC8[0xA1C - 0xC8];
    char mA1C[8];
    void* mA24;
    char padA28[0x14];
    Holder_001CB9C8* mA3C;
    char padA40[4];
    Ctl_001CB9C8* mA44;
    char padA48[0xBD0 - 0xA48];
    Vec_001CB9C8 mBD0;
    char padBE0[4];
    float mBE4;
    char padBE8[0xC10 - 0xBE8];
    Vec_001CB9C8 mC10;
    char padC20[0x10];
    Vec_001CB9C8 mC30;
    float mC40;
    float mC44;
    char padC48[0xC80 - 0xC48];
    int mC80;
    void (Obj_001CB9C8::*mC84)();
    virtual void Dummy();
    int Start();
};

extern void (Obj_001CB9C8::*D_0038D818[])();
extern "C" int func_002695E8(void* a, Vec_001CB9C8* pos, float f0, float f1, int z, Obj_001CB9C8* o,
                             Vec_001CB9C8* out, void* p);
struct Pair_001CB9C8 {
    Vec_001CB9C8 a;
    Vec_001CB9C8 b;
};
extern "C" void func_001C4210(Obj_001CB9C8* o, Pair_001CB9C8* out, float s);
extern "C" void func_001BF130(Obj_001CB9C8* o, int state);

static inline float GetF_001CB9C8(unsigned int id)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), id, &v, 1);
    return v;
}

int Obj_001CB9C8::Start()
{
    if (mA44->m5B0->mA0) {
        return 0;
    }
    void* g = D_0038FC78->m28;
    Vec_001CB9C8* pos = &m30;
    float a = GetF_001CB9C8(0xA2735DD9);
    float b = GetF_001CB9C8(0xC4C164E8);
    Vec_001CB9C8 out;
    if (!func_002695E8(g, pos, a, b, 0, this, &out, mA1C)) {
        return 0;
    }
    mA24 = D_0038FC78->m28;
    mA3C->Release();
    m50 = 0;
    m40.Set(0.0f, 0.0f, 0.0f);
    mC10 = m30;
    mC30 = out;
    mC84 = D_0038D818[0];
    mC44 = 0.0f;
    mC40 = mC4;
    Pair_001CB9C8 v;
    func_001C4210(this, &v, 1.0f);
    mC80 = 1;
    mBD0 = v.a;
    mBE4 = m30.y;
    func_001BF130(this, 4);
    m90 = 0xD63ADCAD;
    return 1;
}
