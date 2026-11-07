typedef int qword_001CB7D0 __attribute__((mode(TI)));

struct Vec_001CB7D0 {
    union {
        struct { float x, y, z, w; };
        qword_001CB7D0 q;
    };
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Vec2_001CB7D0 {
    Vec_001CB7D0 a;
    Vec_001CB7D0 b;
};

struct Pair_001CB7D0 {
    int a;
    int b;
};

extern int D_00388A70;
extern Pair_001CB7D0 D_0038D810[];

extern "C" void func_0010A8D8(int pool, void* p);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" int func_0010FC30();
extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int assert);

struct Ref_001CB7D0 {
    void* m_p;
    void Release()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        func_0010A8D8(D_00388A70, this);
    }
};

struct Thing_001CB7D0 {
    char m_pad[0x1C];
    Ref_001CB7D0* m1C;
    int m20;
};

struct C_001CB7D0 {
    char m_pad[0xA0];
    int mA0;
};

struct B_001CB7D0 {
    char m_pad[0x5B0];
    C_001CB7D0* m5B0;
};

struct Game_001CB7D0 {
    char m_pad[0x28];
    void* m28;
};

extern Game_001CB7D0* D_0038FC78;

struct Skater_001CB7D0;
extern "C" bool func_002695E8(void* world, Vec_001CB7D0* pos, float a, float b, int c, Skater_001CB7D0* s,
                              Vec_001CB7D0* out, void* x);
extern "C" void func_001C4210(Skater_001CB7D0* s, Vec2_001CB7D0* out, float a);
extern "C" void func_001BF130(Skater_001CB7D0* s, int state);

struct Skater_001CB7D0 {
    char m_pad0[0x30];
    Vec_001CB7D0 m30;
    Vec_001CB7D0 m40;
    int m50;
    char m_pad54[0x3C];
    unsigned int m90;
    char m_pad94[0x30];
    float mC4;
    char m_padC8[0x954];
    char mA1C[8];
    void* mA24;
    char m_padA28[0x14];
    Thing_001CB7D0* mA3C;
    int mA40;
    B_001CB7D0* mA44;
    char m_padA48[0x188];
    Vec_001CB7D0 mBD0;
    float mBE0;
    float mBE4;
    char m_padBE8[0x28];
    Vec_001CB7D0 mC10;
    char m_padC20[0x10];
    Vec_001CB7D0 mC30;
    float mC40;
    int mC44;
    char m_padC48[0x38];
    int mC80;
    Pair_001CB7D0 mC84;
    bool Bail(bool alt);
};

bool Skater_001CB7D0::Bail(bool alt)
{
    if (mA44->m5B0->mA0)
        return false;
    void* world = D_0038FC78->m28;
    Vec_001CB7D0* pos = &m30;
    Vec_001CB7D0 out;
    Vec2_001CB7D0 dir;
    float a;
    if (alt) {
        float t;
        func_001E7EB0(func_001E5548(0x6775E538, 0), 0x0EECD255, &t, 1);
        a = t;
    } else {
        float t;
        void* params = func_001E5548(0x6775E538, 0);
        func_001E7EB0(params, 0xA2735DD9, &t, 1);
        a = t;
    }
    float b;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0xC4C164E8, &b, 1);
    if (!func_002695E8(world, pos, a, b, 1, this, &out, mA1C))
        return false;
    Thing_001CB7D0* t = mA3C;
    mA24 = D_0038FC78->m28;
    Ref_001CB7D0* r = t->m1C;
    if (r) {
        r->Release();
        t->m1C = 0;
        t->m20 = func_0010FC30();
    }
    m50 = 0;
    m40.Set(0.0f, 0.0f, 0.0f, 1.0f);
    mC10 = m30;
    mC30 = out;
    mC84 = D_0038D810[0];
    mC44 = 0;
    mC40 = mC4;
    func_001C4210(this, &dir, 1.0f);
    mC80 = 1;
    mBD0 = dir.a;
    mBE4 = out.y;
    func_001BF130(this, 4);
    m90 = 0xE2524194;
    return true;
}
