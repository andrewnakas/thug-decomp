/* fuzzy: 99.6 */
extern "C" float sqrtf(float);
struct Vec_001B1340;
extern "C" void func_003233B8(Vec_001B1340* d, Vec_001B1340* s);
typedef int qword __attribute__((mode(TI)));

struct Vec_001B1340 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001B1340() {}
    Vec_001B1340(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001B1340 operator-(const Vec_001B1340& o) const { return Vec_001B1340(x - o.x, y - o.y, z - o.z, w - o.w); }
    Vec_001B1340 operator+(const Vec_001B1340& o) const { return Vec_001B1340(x + o.x, y + o.y, z + o.z, w + o.w); }
    Vec_001B1340 operator*(float s) const { return Vec_001B1340(x * s, y * s, z * s, w * s); }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    void Normalize() { func_003233B8(this, this); }
    Vec_001B1340& Normalized()
    {
        func_003233B8(this, this);
        return *this;
    }
};

struct Mat_001B1340 {
    Vec_001B1340 r[4];
    const Vec_001B1340& operator[](int i) const { return r[i]; }
    Mat_001B1340& operator=(const Mat_001B1340& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

struct Model_001B1340 {
    char pad0[0x50];
    Vec_001B1340 m_pos;
    char pad60[0x60];
    Mat_001B1340 m_mat;
};

struct Comp_001B1340 {
    char pad0[0x1C];
    unsigned int m1C;
    char pad20[0x10];
    float m30;
    float m34;
};

struct Thing_001B1340 {
    char pad[0xBC];
    void* mBC;
};

struct Script_001B1340 {
    char pad[0x18];
    void* m18;
};

extern char D_00362AB0[];
extern char D_00362AC0[];
extern char D_00362AD0[];
extern char D_00362B08[];

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_00100DC0(Mat_001B1340* m, int axis);
extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" Comp_001B1340* func_00185578(Model_001B1340* m, unsigned int name);
extern "C" void func_001B3538(void* self);
extern "C" void func_001B3CF8(void* self);
extern "C" void func_001B5F30(void* self);
extern "C" float func_001E5318(unsigned int name, int flag);
extern "C" int func_001E72B0(void* s, unsigned int name, float v);
extern "C" int func_001E7318(void* s, const char* name, float v);
extern "C" int func_001E7360(void* s, unsigned int name, int v);
extern "C" int func_001E7528(void* s, unsigned int name, Vec_001B1340* v);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7F50(void* params, const char* name, float* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" Thing_001B1340* func_001F0750(unsigned int name, void* params, int a, int b, int c,
                                         int d, int e, int f, int g, int h);
extern "C" void* func_00229DF0(int node);
extern "C" int func_00229F00(void* node, int i);
extern "C" void func_0022A090(int node, Vec_001B1340* out);
extern "C" int func_00259C30(void* mgr, Model_001B1340* m, int node);
extern "C" void* func_00259EB8();
extern "C" void func_00270C68(Comp_001B1340* c, float v);
extern "C" void func_00270D00(Comp_001B1340* c, float v);
extern "C" void func_003233B8(Vec_001B1340* d, Vec_001B1340* s);

static inline void SetRef_001B1340(void** ref, void* obj)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
    *ref = obj;
    if (obj) func_00183C98(obj, ref);
}

struct C_001B1340 {
    char pad0[0xC];
    Model_001B1340* mC;
    char pad10[0xC];
    unsigned int m1C;
    union {
        int m20;
        struct {
            unsigned long f0 : 1, f1 : 1, f2 : 1, f3 : 1, f4 : 1, f5 : 1, f6 : 58;
        } bits;
    };
    char pad28[0x1C];
    int m44;
    int m48;
    int m4C;
    Vec_001B1340 m50;
    Vec_001B1340 m60;
    char pad70[0x18];
    int m88;
    char pad8C[0x38];
    float mC4;
    float mC8;
    float mCC;
    char padD0[0x60];
    Mat_001B1340 m130;
    Vec_001B1340 m170[5];
    float m1C0;
    Vec_001B1340 ToTarget() const
    {
        return Vec_001B1340(m60.x - mC->m_pos.x, m60.y - mC->m_pos.y, m60.z - mC->m_pos.z, m60.w - mC->m_pos.w);
    }
    int Call(unsigned int name, void* params, Script_001B1340* script);
};

int C_001B1340::Call(unsigned int name, void* params, Script_001B1340* script)
{
    switch (name) {
    case 0x3685B765:
        func_001E8398(params, 0, &m1C, 1);
        break;
    case 0xE9906815: {
        m48 = func_00229F00(func_00229DF0(m44), 0);
        func_0022A090(m48, &m60);
        func_001B3CF8(this);
        m20 |= 2;
        m88 = func_00259C30(func_00259EB8(), mC, m48);
        func_00185578(mC, 0x0A015E17)->m1C |= 0x10;
        Vec_001B1340 dir;
        Vec_001B1340 d;
        d.x = m60.x - m50.x;
        d.y = m60.y - m50.y;
        d.z = m60.z - m50.z;
        d.w = m60.w - m50.w;
        func_003233B8(&d, &d);
        dir = d;
        Mat_001B1340 m = mC->m_mat;
        m.r[2] = dir;
        func_00100DC0(&m, 2);
        mC->m_mat = m;
        m130 = m;
        d = mC->m_pos;
        Vec_001B1340* p = m170;
        for (int i = 4; i >= 0; i--)
            *p++ = d;
        break;
    }
    case 0x0D711542:
        if (m20 & 0x1000) {
            Thing_001B1340* th = func_001F0750(0xBED339D4, 0, 0, 0, -1, 0, 0, 0, 0, 0);
            SetRef_001B1340(&th->mBC, mC);
            m20 &= ~0x1000u;
        }
        m20 |= 2;
        break;
    case 0xCC85ADFE:
        m20 &= ~2u;
        break;
    case 0x68D298B0:
        return (m20 >> 1) & 1;
    case 0x2CC086DD:
        func_001E7F50(params, D_00362AB0, &mC4, 0);
        func_001E7F50(params, D_00362AC0, &mC8, 0);
        func_00103F28(D_00362AD0, mC4, mC8);
        break;
    case 0xC643E8F5: {
        int on = 0;
        func_001E7DE8(params, 0, &on, 1);
        if (on)
            m20 |= 4;
        else
            m20 &= ~4u;
        break;
    }
    case 0x13713760:
        func_001E72B0(script->m18, 0x41272956, func_00185578(mC, 0x0A015E17)->m34);
        break;
    case 0xF5627596:
        mCC = func_00185578(mC, 0x0A015E17)->m30;
        break;
    case 0xE575EFA9:
        func_001E7318(script->m18, D_00362B08, mCC);
        break;
    case 0xEE24A410:
        func_001B5F30(this);
        break;
    case 0x0C076D74: {
        int on;
        func_001E7DE8(params, 0, &on, 1);
        if (func_001E8708(params, 0x255ED86F)) {
            if (!on)
                m20 &= ~0x80u;
            else
                m20 |= 0x80;
        } else {
            if (!on)
                m20 &= ~0x40u;
            else
                m20 |= 0x40;
        }
        break;
    }
    case 0xDA7BE9E2: {
        float height;
        float gravity;
        func_001E7EB0(params, 0x0AB21AF0, &height, 1);
        func_001E7EB0(params, 0xA5E2DA58, &gravity, 1);
        Vec_001B1340 d = ToTarget();
        float h = -height;
        float vup = sqrtf((gravity + gravity) * h);
        float t = sqrtf((h + h) / gravity);
        t = t + t;
        float dist = d.Length() * 0.5f;
        dist = dist * func_001E5318(0x2B5BEDBA, 1);
        d.Normalize();
        dist = dist / t;
        Vec_001B1340 hv(d.x * dist, d.y * dist, d.z * dist, d.w * dist);
        Vec_001B1340 uv = Vec_001B1340(0.0f, 1.0f, 0.0f, 1.0f) * vup;
        Vec_001B1340 dir = hv + uv;
        float speed = dir.Length();
        Vec_001B1340 vel = hv + uv;
        dir = vel.Normalized();
        func_001E7528(script->m18, 0xFD4BC03E, &vel);
        func_001E72B0(script->m18, 0x1C4C5690, speed);
        func_001E72B0(script->m18, 0x66CED87B, t);
        break;
    }
    case 0x1AFFFFB3:
        func_001B3538(this);
        break;
    case 0x5C794C57: {
        int on;
        func_001E7DE8(params, 0, &on, 1);
        if (!on)
            m20 &= ~1u;
        else
            m20 |= 1;
        break;
    }
    case 0x5BB23915:
        return bits.f3 || bits.f4 || bits.f5;
    case 0x56D9F55F: {
        Comp_001B1340* c = func_00185578(mC, 0x187574FA);
        if (c)
            func_00270D00(c, m1C0);
        break;
    }
    case 0x749DE914: {
        Comp_001B1340* c = func_00185578(mC, 0x187574FA);
        if (c)
            func_00270C68(c, m1C0);
        break;
    }
    case 0x58A588B5:
        func_001E7360(script->m18, 0xD14CD5BC, m48);
        func_001E7360(script->m18, 0x8141D319, m44);
        func_001E7360(script->m18, 0x3C746255, m4C);
        break;
    default:
        return 2;
    }
    return 1;
}
