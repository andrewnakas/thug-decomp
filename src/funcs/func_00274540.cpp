typedef int qword_00274540 __attribute__((mode(TI)));

struct Vec_00274540 {
    qword_00274540 q;
};

struct Body_00274540 {
    char pad[0x18];
    unsigned int m_18;
    char pad1C[0x50 - 0x1C];
    Vec_00274540 m_50;
    Vec_00274540 m_60;
    char pad70[0x10];
    Vec_00274540 m_80;
    char pad90[0xB0 - 0x90];
    float m_B0;
    char padB4[4];
    float m_B8;
};

struct State_00274540 {
    char pad[0x1C];
    int m_1C;
    int m_20;
    char pad24[0x7C - 0x24];
    int m_7C;
    char pad80[0xA0 - 0x80];
    int m_A0;
    char padA4[0x13C - 0xA4];
    int m_13C;
    char pad140[0x150 - 0x140];
    int m_150;
    char pad154[0x160 - 0x154];
    Vec_00274540 m_160;
    Vec_00274540 m_170;
    int m_180;
};

struct Info_00274540 {
    char pad[0x1298];
    unsigned int m_1298;
};

struct AnimBase_00274540 {
    char pad[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6(int on);
};

struct Anim_00274540 : AnimBase_00274540 {
    char pad1C[0x50 - 0x1C];
    int m_50;
    int m_54;
    char pad58[0x7C - 0x58];
    int m_dirty;
    char pad80[0x84 - 0x80];
    int m_84;
    int m_88;
    char pad8C[0x94 - 0x8C];
    int m_94;
    void Set54(int v) { int d = m_dirty; int n = d | 1; if (m_54 == v) n = d; m_54 = v; m_dirty = n != 0; }
    void Set50(int v) { int d = m_dirty; if (m_50 != v) d |= 1; m_50 = v; m_dirty = d != 0; }
    void Set88(int v) { int d = m_dirty; if (m_88 != v) d |= 1; m_88 = v; m_dirty = d != 0; }
};

extern void* D_00392068;
extern void* D_0038FC78;
extern "C" float sqrtf(float);
extern "C" void* func_0010FAC8();
extern "C" float func_0033E9B8(void* p);
extern "C" void* func_002A56E0(void* net);
extern "C" int func_002B1FE8(void* item);
extern "C" int func_002B1FF8(void* item);
extern "C" bool func_002A24D8(void* net);
extern "C" void* func_0022E358(void* self);
extern "C" unsigned int func_0024F938(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_001E6AE8(void* params, int a);
extern "C" Anim_00274540* func_00185578(void* obj, unsigned int name);
extern "C" void func_002708F8(Anim_00274540* a, float v);

struct Sk_00274540;
extern "C" void func_00277740(Sk_00274540* self);
extern "C" void func_00276958(Sk_00274540* self);
extern "C" void func_002768F0(Sk_00274540* self);
extern "C" void func_00277270(Sk_00274540* self);

struct Sk_00274540 {
    char pad[0xC];
    Body_00274540* m_C;
    char pad10[0x50 - 0x10];
    Vec_00274540 m_50;
    char pad60[0x2A4 - 0x60];
    float m_2A4;
    int m_2A8;
    Info_00274540* m_2AC;
    char pad2B0[0x2B8 - 0x2B0];
    State_00274540* m_2B8;
    void Update();
};

void Sk_00274540::Update()
{
    void* net = D_00392068;
    m_2A4 = func_0033E9B8(func_0010FAC8());
    void* game = D_0038FC78;
    bool wasRail = m_2B8->m_1C == 3;
    if (m_2B8->m_1C != 1) {
        m_2B8->m_160 = m_C->m_80;
        m_2B8->m_170 = m_C->m_80;
    }
    func_00277740(this);
    m_50 = m_C->m_50;
    m_C->m_60 = m_C->m_50;
    func_00276958(this);
    void* pl = func_002A56E0(net);
    if (!func_002B1FE8(pl) && !func_002B1FF8(pl)) {
        if (func_002A24D8(D_00392068) || func_0024F938(func_0022E358(game)) == 0xBFF33600 || func_0024F938(func_0022E358(game)) == 0x3D6D444F) {
            func_002768F0(this);
        }
    }
    func_00277270(this);
    if (wasRail && m_2B8->m_1C != 3) {
        m_2B8->m_150 = 0;
        if (m_2B8->m_1C == 1) {
            if (__builtin_fabsf(m_C->m_B0) < 1.0f && __builtin_fabsf(m_C->m_B8) < 1.0f)
                m_2B8->m_150 = 1;
        }
    }
    State_00274540* st = m_2B8;
    if (st->m_1C != 1)
        st->m_150 = 0;
    if (m_2B8->m_180 && m_2AC->m_1298) {
        void* params = func_001E6978(func_001190D0(8));
        func_001E7360(params, 0x5B24FAAA, m_C->m_18);
        func_001E7360(params, 0x81CFF663, m_2AC->m_1298);
        func_001F0210(0x7853F8C4, params, 0, 0, 0);
        if (params) {
            func_001E6AE8(params, 3);
        }
    } else {
        bool stopped = !m_2B8->m_180;
        if (stopped && m_2A8) {
            void* params = func_001E6978(func_001190D0(8));
            func_001E7360(params, 0x5B24FAAA, m_C->m_18);
            func_001F0210(0x0F02E44F, params, 0, 0, 0);
            if (params) {
                func_001E6AE8(params, 3);
            }
        }
    }
    m_2A8 = m_2B8->m_180;
    Anim_00274540* a = func_00185578(m_C, 0xB5F1E9D2);
    if (!m_2B8->m_20) {
        if (a->m_94 != 1) {
            a->V6(0);
            a->m_94 = 1;
        }
        func_002708F8(a, sqrtf(m_C->m_B0 * m_C->m_B0 + m_C->m_B8 * m_C->m_B8) * 0.001f);
        a->Set54(m_2B8->m_1C);
        a->Set50(m_2B8->m_13C);
        a->m_84 = m_2B8->m_A0;
        a->Set88(m_2B8->m_7C);
    } else if (a->m_94) {
        a->V6(1);
        a->m_94 = 0;
    }
}
