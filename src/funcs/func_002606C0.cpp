extern "C" float fabsf(float);
struct Info_002606C0 {
    char pad[0x1C];
    unsigned int m_type;
};

struct Stats_002606C0 {
    char pad[0x1544];
    float m1544;
};

struct Holder_002606C0 {
    char pad[0x1C];
    Stats_002606C0* m1C;
};

struct Rec_002606C0 {
    char pad[0x5C];
    short m5C;
};

struct Comp_002606C0 {
    char pad[0x29C];
    Rec_002606C0* m29C;
};

extern "C" Comp_002606C0* func_00185578(void* o, unsigned int crc);
extern "C" int func_0026A958(Rec_002606C0* r, int id);
extern "C" float func_00291220(Info_002606C0* info, unsigned int crc);
extern "C" float func_001E5318(unsigned int crc, int a);
extern "C" int func_00100030(int n);
extern "C" int func_0010FC30();

static inline float Sign_002606C0(float x)
{
    float s = 1.0f;
    if (x < 0.0f)
        s = -1.0f;
    return s;
}

struct Obj_002606C0 {
    int m0;
    void* m4;
    Info_002606C0* m8;
    Holder_002606C0* mC;
    char pad10[0x30 - 0x10];
    int m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
    int m5C;
    int m60;
    int m64;
    int m68;
    int m6C;
    void Init(int a, int b, int c, int d, int e);
};

void Obj_002606C0::Init(int a, int b, int c, int d, int e)
{
    m50 = a;
    m54 = b;
    m58 = c;
    m68 = d;
    m6C = e;
    m30 = 0;
    m48 = 0;
    if (m8->m_type == 0x255ED86F || m8->m_type == 0x8D10119D) {
        Rec_002606C0* r = func_00185578(m4, 0x5BD63B29)->m29C;
        if (m5C != -1) {
            if (func_0026A958(r, m5C)) {
                m34 += func_00291220(m8, 0xFBEC5B6C);
            } else {
                m34 -= func_00291220(m8, 0xC5E1C8EB);
                if (m34 < 0.0f)
                    m34 = 0.0f;
                m44 = 0.0f;
            }
        }
        m5C = r->m5C;
        float t = mC->m1C->m1544;
        if (t < 0.5f) {
            m34 += func_001E5318(0xF54CA12F, 0) * 0.5f / t;
            m3C += func_001E5318(0x30990680, 0) * Sign_002606C0(m40) * 0.5f / t;
        }
    }
    float max = func_00291220(m8, 0x8F4DB5D3);
    if (fabsf(m40) != 0.0f) {
        m40 *= func_00291220(m8, 0x93DD6A10);
        if (fabsf(m40) < max)
            m40 = max * Sign_002606C0(m40);
    } else {
        m40 = max;
        switch (m8->m_type) {
        case 0xEF24413B:
            break;
        case 0x0AC90769:
            m40 = -max;
            break;
        default:
            if (func_00100030(2))
                m40 = -m40;
            break;
        }
    }
    m3C *= func_00291220(m8, 0x6CE10EA4);
    m3C += m44 * Sign_002606C0(m3C);
    float lim = func_00291220(m8, 0xF81AB0E9);
    if (lim < fabsf(m3C)) {
        m3C = lim * 0.9f;
        float a = fabsf(m3C);
        m3C = a * Sign_002606C0(m40);
        m40 = Sign_002606C0(m40) * lim;
    }
    m44 = func_00291220(m8, 0x1231AE3C);
    m60 = 0;
    m4C = func_0010FC30();
}
