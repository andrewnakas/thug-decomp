extern "C" unsigned int func_0010FC30();
extern "C" unsigned int func_0033EBE0(float f);
struct Vec_001BF130 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Timers_001BF130 {
    char pad[0x274];
    unsigned int m_end0;
    unsigned int m_end1;
};

static inline unsigned int EndTime_001BF130(float seconds)
{
    return func_0010FC30() + func_0033EBE0(seconds * 1000.0f);
}

struct State_001BF130 {
    char pad[0x24];
    Timers_001BF130 m_timers;
};

extern float D_00387A7C;
extern "C" void* func_001E5548(unsigned int name, int flag);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);

struct C_001BF130 {
    char pad[0x1C];
    unsigned int m_mode;
    unsigned int m_modeTime;
    unsigned int m_prevMode;
    char pad28[0x98];
    int mC0;
    char padC4[0x964];
    State_001BF130* mA28;
    char padA2C[0x34];
    int mA60;
    int mA64;
    char padA68[0xF0];
    int mB58;
    float mB5C;
    int mB60;
    char padB64[0x2C];
    int mB90;
    char padB94[0xC];
    Vec_001BF130 mBA0;
    char padBB0[0x10];
    int mBC0;
    char padBC4[0x3C];
    int mC00;
    char padC04[0x6C];
    Vec_001BF130 mC70;
    void SetMode(unsigned int mode);
};

void C_001BF130::SetMode(unsigned int mode)
{
    if (mode == m_mode)
        return;
    m_prevMode = m_mode;
    m_mode = mode;
    m_modeTime = func_0010FC30();
    if (m_prevMode < 2) {
        mA64 = 0;
        mA60 = 0;
    }
    if (m_prevMode == 1) {
        mB90 = 0;
        mBA0.Set(0.0f, 0.0f, 0.0f, 1.0f);
        mC0 = 0;
    }
    if (m_mode == 0) {
        mB60 = 1;
        mB5C = D_00387A7C;
    }
    if (m_mode == 4)
        mC70.Set(0.0f, 0.0f, 0.0f, 1.0f);
    if (m_mode != 1)
        mBC0 = 0;
    if (m_mode == 0 || m_prevMode != 1)
        mB58 = 0;
    if (m_mode == 2) {
        mC00 = 0;
        if (m_prevMode == 1) {
            Timers_001BF130* t = &mA28->m_timers;
            float a;
            func_001E7EB0(func_001E5548(0x6775E538, 0), 0xAC96D24B, &a, 1);
            t->m_end0 = EndTime_001BF130(a);
            float b;
            func_001E7EB0(func_001E5548(0x6775E538, 0), 0xAC96D24B, &b, 1);
            t->m_end1 = EndTime_001BF130(b);
        }
    }
}
