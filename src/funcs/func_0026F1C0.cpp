struct Btn_0026F1C0 {
    char pad[0x24];
};

struct Pad_0026F1C0 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
    unsigned char m6;
    unsigned char m7;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    unsigned char mB;
    unsigned char mC;
    unsigned char mD;
    unsigned char mE;
    unsigned char mF;
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
    unsigned char m13;
    unsigned char m14;
    unsigned char m15;
    unsigned char m16;
    unsigned char pad17[5];
    int m1C;
};

extern "C" void func_0026FC00(Btn_0026F1C0* b, int v);
extern "C" float func_003414F0(float y, float x);
extern "C" float func_0026F908(int b7, int b8, int b6, int b5);
extern "C" unsigned int func_0010FC30();
extern "C" float sqrtf(float);
static inline float fabsf(float x) { return __builtin_fabsf(x); }

static inline float Axis_0026F1C0(int v)
{
    if (v > 0)
        return (float)(v - 50) * 0.01298701297f;
    return (float)(v + 50) * 0.01298701297f;
}

struct Ctrl_0026F1C0 {
    int m0;
    Btn_0026F1C0 mBtn[16];
    float m244;
    float m248;
    float m24C;
    float m250;
    float m254;
    float m258;
    float m25C;
    float m260;
    float m264;
    float m268;
    float m26C;
    float m270;
    unsigned int m274;
    unsigned int m278;
    void Read(const Pad_0026F1C0* d);
};

void Ctrl_0026F1C0::Read(const Pad_0026F1C0* d)
{
    func_0026FC00(&mBtn[0], d->m7 ? 255 : 0);
    func_0026FC00(&mBtn[1], d->m8 ? 255 : 0);
    func_0026FC00(&mBtn[2], d->m6 ? 255 : 0);
    func_0026FC00(&mBtn[3], d->m5 ? 255 : 0);
    func_0026FC00(&mBtn[11], d->mC ? 255 : 0);
    func_0026FC00(&mBtn[10], d->mA ? 255 : 0);
    func_0026FC00(&mBtn[13], d->mB ? 255 : 0);
    func_0026FC00(&mBtn[12], d->m9 ? 255 : 0);
    func_0026FC00(&mBtn[4], d->mD ? 255 : 0);
    func_0026FC00(&mBtn[7], d->mE ? 255 : 0);
    func_0026FC00(&mBtn[5], d->mF ? 255 : 0);
    func_0026FC00(&mBtn[8], d->m10 ? 255 : 0);
    func_0026FC00(&mBtn[6], (d->m1C & 0x200) ? 255 : 0);
    func_0026FC00(&mBtn[9], (d->m1C & 0x400) ? 255 : 0);
    func_0026FC00(&mBtn[15], (d->m1C & 0x100) ? 255 : 0);
    int vm1 = d->m1 - 128;
    if (vm1 == 0) {
        m254 = 0.0f;
    } else {
        if (vm1 == -128) vm1 = -127;
        m254 = Axis_0026F1C0(vm1);
    }
    int vm2 = d->m2 - 128;
    if (vm2 == 0) {
        m258 = 0.0f;
    } else {
        if (vm2 == -128) vm2 = -127;
        m258 = Axis_0026F1C0(vm2);
    }
    int vm3 = d->m3 - 128;
    if (vm3 == 0) {
        m25C = 0.0f;
    } else {
        if (vm3 == -128) vm3 = -127;
        m25C = Axis_0026F1C0(vm3);
    }
    int vm4 = d->m4 - 128;
    if (vm4 == 0) {
        m260 = 0.0f;
    } else {
        if (vm4 == -128) vm4 = -127;
        m260 = Axis_0026F1C0(vm4);
    }
    m244 = (float)(d->m13 - 128);
    m248 = (float)(d->m14 - 128);
    m24C = (float)(d->m15 - 128);
    m250 = (float)(d->m16 - 128);
    m268 = sqrtf(m244 * m244 + m248 * m248);
    m264 = func_003414F0(m244, -m248);
    m270 = sqrtf(m24C * m24C + m250 * m250);
    if (m270 > 0.001f) {
        m26C = func_003414F0(m24C, -m250);
    } else {
        int b7 = d->m7 != 0;
        int b8 = d->m8 != 0;
        int b6 = d->m6 != 0;
        int b5 = d->m5 != 0;
        if (b7 || b8 || b6 || b5) {
            m26C = func_0026F908(b7, b8, b6, b5);
            m270 = 127.0f;
        } else {
            m26C = 0.0f;
            m270 = 0.0f;
        }
    }
    if (m274) {
        if (m270 == 0.0f || fabsf(m26C) >= 0.7853982449f || (float)func_0010FC30() > (float)m274)
            m274 = 0;
    }
    if (m278) {
        if (m270 == 0.0f || 3.141592741f - fabsf(m26C) >= 0.7853982449f || (float)func_0010FC30() > (float)m278)
            m278 = 0;
    }
}
