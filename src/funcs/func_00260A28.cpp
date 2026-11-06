extern "C" float fabsf(float);
extern "C" float func_0010FAB8();
extern "C" unsigned int func_0010FC30();
extern "C" void* func_002A39D8(void* net);
extern "C" void* func_002A52F0(void* net, unsigned short id);
extern "C" float func_00291220(void* p, unsigned int name);
extern "C" void func_00237A30(void* p, int v);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001F4850(void* p, void* q, int a, float t);
extern "C" unsigned int func_001E5628(unsigned int name, int a);
extern "C" int func_00100030(int n);
extern "C" void* func_00121960(int size);
extern "C" void* func_001EE428(void* mem);
extern "C" void func_001848F0(void* obj, unsigned int name, int a);
extern "C" void func_001A12B8(void* p, float t, int a);
extern "C" void func_00239178(void* p, int a, float f);
extern "C" void func_00239158(void* p, int a, float f);

struct Timer_00260A28 {
    int m0;
    int m4;
};
extern "C" Timer_00260A28* func_0026F6C0(void* table, unsigned int id);

extern void* D_00392068;

struct Owner_00260A28 {
    char pad0[0x14];
    void* m14;
    unsigned short m18;
};
struct Params_00260A28 {
    char pad0[0x1C];
    void* m1C;
};
struct Sub_00260A28 {
    char pad0[0x34];
    int m34;
};
struct Comp_00260A28 {
    char pad0[0x5B0];
    Sub_00260A28* m5B0;
};
struct Cont_00260A28 {
    char pad0[0x24];
    char m24[4];
};
struct Obj_00260A28 {
    int m0;
    Owner_00260A28* m4;
    Params_00260A28* m8;
    Params_00260A28* mC;
    Cont_00260A28* m10;
    char pad14[0x30 - 0x14];
    float m30;
    float m34;
    char pad38[0x3C - 0x38];
    float m3C;
    float m40;
    float m44;
    int m48;
    unsigned int m4C;
    unsigned int m50;
    unsigned int m54;
    int m58;
    char pad5C[0x60 - 0x5C];
    int m60;
    int m64;
    int m68;
    int m6C;
    void Update();
};

static inline unsigned int Since_00260A28(unsigned int t) { return func_0010FC30() - t; }

void Obj_00260A28::Update()
{
    float dt = func_0010FAB8();
    if (!m50 || !m54) return;
    void* net = D_00392068;
    if (func_002A39D8(net)) func_002A52F0(net, m4->m18);
    if (m44 > 0.01f) {
        float r = func_00291220(m8, 0x1231AE3C) / func_00291220(m8, 0xA4362662);
        m44 -= r * dt * 60.0f;
        if (m44 < 0.0f) m44 = 0.0f;
    }
    func_00237A30(mC->m1C, m58);
    m30 += dt;
    m34 += dt;
    func_001F4850(func_00185578(m4, 0x4FF8DAC6), m8->m1C, 0, m30);
    float k1 = func_00291220(m8, 0x06851748);
    float k2 = func_00291220(m8, 0xA9FEF5AB);
    float k3 = func_00291220(m8, 0xB6A634F3);
    float c = k3 + m34 * k2;
    m3C = m3C + m3C * k1 * c * dt * 60.0f + m40 * c * dt * 60.0f;
    int left = func_0026F6C0(m10->m24, m50)->m4;
    int right = func_0026F6C0(m10->m24, m54)->m4;
    if (!left && !right) m48 = 1;
    unsigned int dur = func_001E5628(0x8CC8F176, 1);
    unsigned int el = Since_00260A28(m4C);
    if (!m48 && func_001E5628(0x07DA1621, 1) < el) m48 = 1;
    if (left && m48) {
        float f = 1.0f;
        if (m3C < 0.0f && el < dur) f = el / dur;
        float d = func_00291220(m8, 0x61AD5596) * dt * 60.0f;
        m40 -= d * f;
    } else if (right && m48) {
        float f = 1.0f;
        if (0.0f < m3C && el < dur) f = el / dur;
        float d = func_00291220(m8, 0x61AD5596) * dt * 60.0f;
        m40 += d * f;
    } else if (fabsf(m40) < func_00291220(m8, 0xEF27E8FF)) {
        int r = func_00100030((int)func_00291220(m8, 0x32EB3308) | 1);
        float s = 1.0f;
        if (m40 < 0.0f) s = -1.0f;
        m40 = r * s;
    } else {
        int r = func_00100030(0x32);
        float s = 1.0f;
        if (m40 < 0.0f) s = -1.0f;
        m40 += (r / 100.0f) * s;
    }
    if (!m4->m14) m4->m14 = func_001EE428(func_00121960(0xF4));
    if (fabsf(m3C) > func_00291220(m8, 0xF81AB0E9)) {
        if (0.0f < m3C) {
            func_001848F0(m4, 0xD77B6FF9, 0);
        } else {
            func_001848F0(m4, 0x47D44B84, 0);
        }
        m3C = 0.0f;
        m8->m1C = 0;
    }
    if (m60) {
        int flip = m6C;
        if (m68) {
            Comp_00260A28* o = (Comp_00260A28*)func_00185578(m4, 0x5BD63B29);
            if (o->m5B0->m34) flip ^= 1;
        }
        void* p = func_00185578(m4, 0x72AD7B23);
        if (p) {
            if (flip) {
                func_001A12B8(p, (4096.0f - m3C) * (1.0f / 8192.0f), 1);
            } else {
                func_001A12B8(p, (m3C + 4096.0f) * (1.0f / 8192.0f), 1);
            }
        }
    }
    float t = -m3C * (1.0f / 4096.0f);
    if (m64) return;
    if (!m8->m1C) return;
    if ((m50 == 0xBC6B118F || m50 == 0xE3006FC4) && (m54 == 0xBC6B118F || m54 == 0xE3006FC4)) {
        if (mC->m1C) func_00239178(mC->m1C, 1, t);
    } else {
        if (mC->m1C) func_00239158(mC->m1C, 1, t);
    }
}
