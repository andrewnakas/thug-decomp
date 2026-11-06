/* fuzzy: 31.6 */
extern float D_00387F88, D_00387F8C, D_00387F90, D_00387F94, D_00387F98, D_00387F9C;   /* the game's .lit4 constants this function loads */
typedef int qword_0027A5F8 __attribute__((mode(TI)));

union Vec_0027A5F8 {
    qword_0027A5F8 q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_0027A5F8() {}
    Vec_0027A5F8(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator+=(const Vec_0027A5F8& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void operator-=(const Vec_0027A5F8& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
    float Length2() const { return c[0] * c[0] + c[1] * c[1] + c[2] * c[2]; }
};

static inline Vec_0027A5F8 operator*(const Vec_0027A5F8& a, float k)
{
    return Vec_0027A5F8(a[0] * k, a[1] * k, a[2] * k, a[3] * k);
}
static inline Vec_0027A5F8 operator+(const Vec_0027A5F8& a, const Vec_0027A5F8& b)
{
    return Vec_0027A5F8(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
static inline Vec_0027A5F8 operator-(const Vec_0027A5F8& a, const Vec_0027A5F8& b)
{
    return Vec_0027A5F8(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
static inline Vec_0027A5F8 Cross_0027A5F8(const Vec_0027A5F8& a, const Vec_0027A5F8& b)
{
    return Vec_0027A5F8(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

struct Mat_0027A5F8 {
    Vec_0027A5F8 r[4];
};

extern "C" float sqrtf(float);
extern "C" unsigned int func_0010FC30();
extern "C" void func_003233B8(Vec_0027A5F8* d, Vec_0027A5F8* s);

/* A value plus the time it last changed; func_0026FDA0 gives the time since. */
struct Flag_0027A5F8 {
    int m0;
    int value;
    unsigned int time;
    void Set(int v)
    {
        if (value != v) {
            value = v;
            time = func_0010FC30();
        }
    }
};

struct Phys_0027A5F8 {
    char pad0[0x1C];
    int state;
    char pad20[0x28 - 0x20];
    int m28;
    char pad2C[4];
    Flag_0027A5F8 f30;
    char pad3C[4];
    int m40;
    char pad44[0x78 - 0x44];
    Flag_0027A5F8 f78;
    char pad84[0x90 - 0x84];
    Flag_0027A5F8 f90;
    Flag_0027A5F8 f9C;
    char padA8[0xC4 - 0xA8];
    int mC4;
    char padC8[4];
    Flag_0027A5F8 fCC;
    char padD8[0x108 - 0xD8];
    Flag_0027A5F8 f108;
    char pad114[0x124 - 0x114];
    int m124;
    char pad128[0x184 - 0x128];
    float m184;
};

struct Info_0027A5F8 {
    char pad0[0x28];
    Flag_0027A5F8 f28;
    char pad34[0x4C - 0x34];
    Flag_0027A5F8 f4C;
    char pad58[0x70 - 0x58];
    Flag_0027A5F8 f70;
    char pad7C[0x98 - 0x7C];
    int m98;
    char pad9C[0xE0 - 0x9C];
    int mE0;
    char padE4[0x14C - 0xE4];
    int m14C;
};

struct Ctrl_0027A5F8 {
    char pad0[0x28];
    int m28;
};

struct Model_0027A5F8 {
    char pad0[0x50];
    Vec_0027A5F8 pos;
    Vec_0027A5F8 oldPos;
    Mat_0027A5F8 mat;
    Vec_0027A5F8 vel;
    char padC0[0x164 - 0xC0];
    int m164;
    char pad168[0x31C - 0x168];
    int m31C;
    int m320;
};

struct Script_0027A5F8 {
    char pad0[0x18];
    void* params;
};

struct List_0027A5F8 {
    char pad0[0xC];
    int size;
};

/* Component with the script member-function hook in slot 11. */
class Comp_0027A5F8 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual int CallMember(unsigned int name, void* params, Script_0027A5F8* script);
};

struct Slot_0027A5F8 {
    int m0;
    char pad4[0xC];
};

struct Game_0027A5F8 {
    char pad0[0x3CC];
    Slot_0027A5F8 slots[8];
};

extern Game_0027A5F8* D_0038FC78;

struct Skater_0027A5F8 {
    char pad0[0xC];
    Model_0027A5F8* mC;
    char pad10[0x20 - 0x10];
    Mat_0027A5F8 m20;
    Vec_0027A5F8 m60;
    Vec_0027A5F8 m70;
    char pad80[0xA0 - 0x80];
    Vec_0027A5F8 mA0;
    char padB0[0x160 - 0xB0];
    Vec_0027A5F8 m160;
    char pad170[0x219 - 0x170];
    char m219;
    char pad21A[0x270 - 0x21A];
    Vec_0027A5F8 m270;
    Vec_0027A5F8 m280;
    char pad290[0x294 - 0x290];
    int m294;
    char pad298[0x29C - 0x298];
    int m29C;
    char pad2A0[0x2B8 - 0x2A0];
    int m2B8;
    int m2BC;
    char pad2C0[0x354 - 0x2C0];
    float m354;
    float m358;
    float m35C;
    char pad360[4];
    int m364;
    char pad368[0x370 - 0x368];
    int m370;
    int m374;
    float m378;
    int m37C;
    unsigned int m380;
    float m384;
    int m388;
    char pad38C[0x3A0 - 0x38C];
    float m3A0;
    float m3A4;
    float m3A8;
    char pad3AC[0x3B4 - 0x3AC];
    float m3B4;
    float m3B8;
    float m3BC;
    float m3C0;
    float m3C4;
    char pad3C8[0x3D4 - 0x3C8];
    int m3D4;
    int m3D8;
    int m3DC;
    int m3E0;
    int m3E4;
    char pad3E8[4];
    int m3EC;
    char pad3F0[0x3F8 - 0x3F0];
    unsigned int m3F8;
    unsigned int m3FC;
    int m400;
    char pad404[0x424 - 0x404];
    int m424;
    int m428;
    int m42C;
    char pad430[0x594 - 0x430];
    Info_0027A5F8* m594;
    char pad598[0x59C - 0x598];
    Ctrl_0027A5F8* m59C;
    char pad5A0[0x5B0 - 0x5A0];
    Phys_0027A5F8* m5B0;
    int CallMemberFunction(unsigned int name, void* params, Script_0027A5F8* script);
    unsigned int StateTime()
    {
        switch (m5B0->state) {
        case 1:
        case 2:
            return func_0010FC30() - m3F8;
        default:
            return m3FC - m3F8;
        }
    }
};

extern "C" float func_002032A0(unsigned int name, int def);
extern "C" int func_00203300(unsigned int name, int def);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" bool func_001E8248(void* params, unsigned int name, List_0027A5F8** out, int req);
extern "C" void func_001E72B0(void* params, unsigned int name, float v);
extern "C" void func_001E7410(void* params, unsigned int name, float x, float y, float z);
extern "C" float func_001E9298(List_0027A5F8* l, int i);
extern "C" unsigned int func_0033EBE0(float f);
extern "C" int func_0026FDA0(Flag_0027A5F8* f);
extern "C" void func_0027C720(Skater_0027A5F8* self, int state);
extern "C" int func_0027D9F0(Skater_0027A5F8* self);
extern "C" void func_0027FDB0(Skater_0027A5F8* self, Vec_0027A5F8* dir);
extern "C" float func_00282C38(Skater_0027A5F8* self, float a, float b, float c);
extern "C" void func_0028DF70(Skater_0027A5F8* self, int a);
extern "C" int func_0028E1C0(Skater_0027A5F8* self, unsigned short a, unsigned short b);
extern "C" void func_0028E2F0(Skater_0027A5F8* self, void* params);
extern "C" void func_0028E830(Skater_0027A5F8* self);
extern "C" void func_0028EAC0(Skater_0027A5F8* self);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001B6BC0(void* c, Vec_0027A5F8* pos);
extern "C" void func_001B6BD0(void* c, Vec_0027A5F8* dir);
extern "C" void func_00186398(Model_0027A5F8* m, int a);
extern "C" void* func_00203EE0(Model_0027A5F8* m);
extern "C" void func_00185058(void* p);
extern "C" void func_00291AD8(void* c);

/* Skater physics script member functions: state queries, timers, jump/push impulses, rail
   probes and flags. Returns 0/1 for handled queries, 2 when the name is not one of ours. */
int Skater_0027A5F8::CallMemberFunction(unsigned int name, void* params, Script_0027A5F8* script)
{
    switch (name) {
    case 0x68BF6C13:
        m370 = 0;
        return 1;
    case 0x0E1D5168:
        return m3D8 != 0;
    case 0x01BAA1D9:
        return m364 == 0;
    case 0x02F66333:
        return func_0027D9F0(this) != 0;
    case 0x0257947E:
        m364 = 0;
        return 1;
    case 0x0C7A712C:
        return m5B0->f30.value != 0;
    case 0x065A559A:
        m424 = 0;
        return 1;
    case 0x05144783:
        func_001E72B0(script->params, 0x7323E97C, mC->mat.r[1][0]);
        func_001E72B0(script->params, 0x0424D9EA, mC->mat.r[1][1]);
        func_001E72B0(script->params, 0x9D2D8850, mC->mat.r[1][2]);
        return 1;
    case 0x0E2998B9:
        m3D4 = 0;
        return 1;
    case 0x133E1293:
        m3E4 = 1;
        return 1;
    case 0x0F922431:
        m3E4 = 0;
        return 1;
    case 0x1996B797: {
        Model_0027A5F8* m = mC;
        float y = m->pos[1];
        void* out = script->params;
        float h = func_00282C38(this, y - m5B0->m184, y, m->vel[1]);
        if (h < 0.0f)
            h = 0.0f;
        func_001E72B0(out, 0x7E2A8993, h);
        return 1;
    }
    case 0x1F8BBD05:
        return m388 != 0;
    case 0x1D1FD4F0: {
        Model_0027A5F8* m = mC;
        m60 = m->mat.r[1];
        Vec_0027A5F8 dir = m160;
        m70 = m->mat.r[1];
        func_0027FDB0(this, &dir);
        return 1;
    }
    case 0x19D0E5FB:
        m3DC = 1;
        return 1;
    case 0x17846595: {
        float vy = mC->vel[1];
        if (vy < 0.0f)
            vy = 0.0f;
        mC->vel[1] = vy;
        mC->vel[1] = mC->vel[1] + func_002032A0(0xCB49B3F2, 0);
        Vec_0027A5F8 h = mC->vel;
        h[1] = 0.0f;
        if (h[0] * h[0] + h[2] * h[2] < 100.0f) {
            h = mC->mat.r[2];
            h[1] = 0.0f;
            if (h[0] * h[0] + h[2] * h[2] < D_00387F8C) {
                h[3] = 1.0f;
                h[0] = 1.0f;
                h[2] = 1.0f;
            }
        }
        func_003233B8(&h, &h);
        mC->vel += h * func_002032A0(0xB7422173, 0);
        return 1;
    }
    case 0x4ADC6C2A:
        return m5B0->m28 != 0;
    case 0x315D9ED4:
        return m2B8 != 0;
    case 0x262D42D5:
        return m5B0->m124 != 0;
    case 0x32DCC9CF:
        func_0028EAC0(this);
        return 1;
    case 0x3527FC07:
        return m5B0->state == 1;
    case 0x448E3630:
        return m3E0 != 0;
    case 0x461E5B92: {
        Model_0027A5F8* m = mC;
        if (m->vel.Length2() < D_00387F94)
            return 1;
        m->mat.r[2] = m->vel;
        func_003233B8(&mC->mat.r[2], &mC->mat.r[2]);
        m = mC;
        m->mat.r[0] = Cross_0027A5F8(m->mat.r[1], m->mat.r[2]);
        func_003233B8(&mC->mat.r[0], &mC->mat.r[0]);
        m = mC;
        m->mat.r[1] = Cross_0027A5F8(m->mat.r[2], m->mat.r[0]);
        func_003233B8(&mC->mat.r[1], &mC->mat.r[1]);
        m20 = mC->mat;
        return 1;
    }
    case 0x383B939B:
        m364 = 1;
        return 1;
    case 0x34DCFC97: {
        float speed = 0.0f;
        func_001E7EB0(params, 0, &speed, 0);
        Model_0027A5F8* m = mC;
        float len2 = m->vel.Length2();
        if (len2 < D_00387F88)
            m->vel = m->mat.r[2];
        else
            m->vel *= 1.0f / sqrtf(len2);
        mC->vel *= speed;
        return 1;
    }
    case 0x510F983B:
        func_001E7EB0(params, 0, &m378, 0);
        if (func_001E8708(params, 0x1CA1FF20) && m384 == 0.0f)
            m378 = func_002032A0(0x78F80EC4, 0);
        return 1;
    case 0x55934543: {
        Vec_0027A5F8 a;
        Vec_0027A5F8 b;
        if (func_001E8708(params, 0xA549B57B)) {
            float k = func_002032A0(0xB92CBE3B, 0);
            float dy = func_002032A0(0xEFDFE781, 0);
            Model_0027A5F8* m = mC;
            m280 = m->pos;
            m280[1] -= dy;
            b = m->mat.r[1] * k;
            m270 = m280 - b;
            if (func_0028E1C0(this, 0x10, 0))
                return m294 != 0;
            k = func_002032A0(0x108613CB, 0);
            dy = func_002032A0(0xF9DC446D, 0);
            m = mC;
            b = m->mat.r[1] * k;
            a = m->pos - b;
            m280 = a;
            m270 = a;
            m280[1] -= dy;
        } else {
            float k = func_002032A0(0xC78EBE56, 0);
            Model_0027A5F8* m = mC;
            b = m->mat.r[0] * k;
            a = m->pos + b;
            float k2 = 2.0f * k;
            a[1] -= func_002032A0(0xFCA3378C, 0);
            Vec_0027A5F8 c = mC->mat.r[0] * k2;
            b = a - c;
            if (func_001E8708(params, 0x85981897)) {
                m270 = a;
                m280 = b;
            } else {
                m270 = b;
                m280 = a;
            }
        }
        if (!func_0028E1C0(this, 0x10, 0))
            return 0;
        return m294 != 0;
    }
    case 0x54EF2B79:
        m3D4 = 1;
        m5B0->f90.Set(0);
        return 1;
    case 0x5CB1FBD8:
        return m5B0->state == 3;
    case 0x5EA287F2:
        return m5B0->state == 0;
    case 0x5E8F9E77:
        m5B0->f108.Set(1);
        return 1;
    case 0x5E8D9B80: {
        List_0027A5F8* l = 0;
        func_001E8248(params, 0, &l, 0);
        if (m37C >= l->size)
            m37C = l->size - 1;
        m378 = func_001E9298(l, m37C);
        if (m37C == 0)
            m380 = func_0010FC30();
        m37C++;
        func_001E7EB0(params, 0x79A07F3F, &m384, 0);
        return 1;
    }
    case 0x584CF9E9:
        func_0028E2F0(this, params);
        return 1;
    case 0x259CB90D: {
        Info_0027A5F8* info = m594;
        Vec_0027A5F8 f = mC->mat.r[2];
        f[1] = 0.0f;
        func_003233B8(&f, &f);
        Vec_0027A5F8 side;
        side[0] = f[2];
        side[1] = 0.0f;
        side[2] = -f[0];
        side[3] = 0.0f;
        if (info->m98)
            return 0;
        if (info->mE0 || info->m14C) {
            mC->vel += f * func_002032A0(0x1F96C224, 0);
            return 1;
        }
        if (info->f70.value && func_0026FDA0(&info->f70) > func_00203300(0x3080E9E7, 0)) {
            mC->vel += f * func_002032A0(0xDC818B7E, 0);
            return 1;
        }
        if (info->f28.value && func_0026FDA0(&info->f28) > func_00203300(0x9B25142A, 0)) {
            mC->vel -= side * func_002032A0(0x1AB3809F, 0);
            return 1;
        }
        if (!info->f4C.value)
            return 0;
        if (func_0026FDA0(&info->f4C) > func_00203300(0x9B25142A, 0)) {
            mC->vel += side * func_002032A0(0x1AB3809F, 0);
            return 1;
        }
        return 0;
    }
    case 0x6C8A1316:
        if (func_001E8708(params, 0x47953F00)) {
            if (!m5B0->f30.value)
                return m428 != 0;
            return m428 == 0;
        }
        if (func_001E8708(params, 0x996D5512)) {
            if (m5B0->f30.value)
                return m428 != 0;
            return m428 == 0;
        }
        return 1;
    case 0x71B993B7:
        func_001E7DE8(params, 0, &m42C, 0);
        return 1;
    case 0x6FC5AAE0:
        m5B0->f9C.Set(1);
        return 1;
    case 0x8C3D7864:
        m3D8 = 0;
        return 1;
    case 0x947FCCF4: {
        unsigned int v = 0;
        func_001E8398(params, 0, &v, 1);
        if (v != 0x8D10119D) {
            m5B0->f78.Set(0);
            m59C->m28 = 0;
        } else {
            m5B0->f78.Set(1);
            m59C->m28 = 1;
        }
        return 1;
    }
    case 0x90F1D8D5:
        if (func_001E8708(params, 0xFF03CC4E)) {
            m3B4 = 0.0f;
            return 1;
        }
        func_001E7EB0(params, 0x6289DD76, &m3B8, 1);
        m3BC = m3B8;
        func_001E7EB0(params, 0x73A19E3A, &m3BC, 0);
        m3B4 = D_00387F98;
        func_001E7EB0(params, 0x906B67BA, &m3B4, 0);
        m3C0 = D_00387F9C;
        func_001E7EB0(params, 0xEDF3E7F4, &m3C0, 0);
        m3C4 = func_002032A0(0x6618A713, 0);
        func_001E7EB0(params, 0xA5E2DA58, &m3C4, 0);
        if (func_001E8708(params, 0xDF312928))
            m3B4 = -1.0f;
        return 1;
    case 0x8F66B80B: {
        int v;
        if (mC->m164)
            v = m5B0->f30.value;
        else
            v = m5B0->f30.value ^ 1;
        return v != 0;
    }
    case 0x8819DD8B: {
        Comp_0027A5F8* c = (Comp_0027A5F8*)func_00185578(mC, 0x0A015E17);
        Model_0027A5F8* m = mC;
        int ok = c->CallMember(0x8819DD8B, params, script) != 0;
        m20 = m->mat;
        void* body = func_00185578(mC, 0x8A897DD2);
        func_001B6BC0(body, &mC->pos);
        func_001B6BD0(body, &mC->mat.r[1]);
        m = mC;
        mA0 = m->pos;
        m->oldPos = m->pos;
        func_00186398(mC, 1);
        m = mC;
        if (m->m31C) {
            void* p = func_00203EE0(m);
            if (p)
                func_00185058(p);
        }
        if (!func_001E8708(params, 0xD607E2E6)) {
            m = mC;
            m219 = 0;
            m->vel = Vec_0027A5F8(0.0f, 0.0f, 0.0f, 1.0f);
            func_0027C720(this, 0);
            m5B0->f30.Set(mC->m164 ^ 1);
            func_00291AD8(func_00185578(mC, 0x488AF07A));
            return ok;
        }
        if (!func_001E8708(params, 0x90A91232))
            return ok;
        float vy = mC->vel[1];
        mC->vel[1] = 0.0f;
        m = mC;
        float speed = sqrtf(m->vel.Length2());
        m->vel = m->mat.r[2] * speed;
        mC->vel[1] = vy;
        return ok;
    }
    case 0xA64DCF8B:
        return m5B0->state == 5;
    case 0x9C6A7E41:
        return m5B0->mC4 != 0;
    case 0xA32C1A15:
        return m5B0->state == 2;
    case 0x9FCFDFEB:
        m364 = D_0038FC78->slots[mC->m320].m0;
        return 1;
    case 0xA901A50C:
        return m5B0->f9C.value != 0;
    case 0xB48EC756:
        m3DC = 0;
        return 1;
    case 0xB94BC0C6:
        m5B0->fCC.Set(func_001E8708(params, 0xD443A2BC) ^ 1);
        return 1;
    case 0xACB82C02:
        m400 = func_001E8708(params, 0xF649D637);
        return 1;
    case 0x948EBF96: {
        unsigned int v = 0;
        func_001E8398(params, 0, &v, 0);
        int st = m5B0->state;
        if (st == 3 && v != 0xA549B57B)
            func_0028DF70(this, 8);
        if (st != 3 || m5B0->state != st) {
            if (v == 0xA549B57B)
                m29C = 0;
        }
        if (m5B0->state == 2) {
            Vec_0027A5F8 up(0.0f, 1.0f, 0.0f, 1.0f);
            func_0027FDB0(this, &up);
            m20 = mC->mat;
        }
        switch (v) {
        case 0x58007C97:
            m219 = 0;
            func_0027C720(this, 0);
            break;
        case 0x439F4704:
            func_0027C720(this, 1);
            break;
        case 0xA549B57B:
            func_0027C720(this, 3);
            break;
        }
        return 1;
    }
    case 0xB9EEBFF6:
        m3EC = 0;
        return 1;
    case 0xE0760055:
        return m3DC != 0;
    case 0xBE371B7B:
        return m2BC != 0;
    case 0x0C890A84:
    case 0xBBF2B570: {
        float t = 0.0f;
        func_001E7EB0(params, 0, &t, 0);
        float ms;
        if (func_001E8708(params, 0xD029F619) || func_001E8708(params, 0x49E0EE96))
            ms = t * 1000.0f;
        else if (func_001E8708(params, 0x019176C5) || func_001E8708(params, 0x4A07C332))
            ms = t * 16.0f;
        else
            ms = t;
        unsigned int limit = func_0033EBE0(ms);
        unsigned int elapsed = StateTime();
        if (name == 0x0C890A84)
            return elapsed < limit;
        return limit < elapsed;
    }
    case 0xBD4303F4:
        m5B0->f9C.Set(0);
        return 1;
    case 0xBC19E291:
        m374 = 1;
        return 1;
    case 0xC5B4B390:
        m3EC = 1;
        return 1;
    case 0xDE583E34:
        func_001E72B0(script->params, 0xAD6BCDB4, (float)StateTime() * D_00387F90);
        return 1;
    case 0xDFB8F052:
        return m5B0->m40 != 0;
    case 0xCA6B3809:
        func_0028E830(this);
        return 1;
    case 0xE9851E62:
        return m5B0->state == 4;
    case 0xE0DF1F0A:
        m3D8 = 1;
        return 1;
    case 0xE8DEB0D7:
        m370 = 1;
        return 1;
    case 0xE47FF4B5:
        m354 = 48.0f;
        m358 = 100.0f;
        m35C = 6.0f;
        func_001E7EB0(params, 0xC48391A5, &m354, 0);
        func_001E7EB0(params, 0xF0D90109, &m358, 0);
        func_001E7EB0(params, 0xDFDFEAB8, &m35C, 0);
        return 1;
    case 0xEBBCF455:
        m374 = 0;
        return 1;
    case 0xF37CE040:
        return m3E4 != 0;
    case 0xF7E21884:
        func_001E7410(script->params, 0x7F261953, m3A0, m3A4, m3A8);
        return 1;
    case 0xEC681A59:
        m424 = 1;
        return 1;
    }
    return 2;
}
