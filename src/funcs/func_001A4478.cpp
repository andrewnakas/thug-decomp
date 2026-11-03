typedef int qword __attribute__((mode(TI)));

struct Vec_001A4478 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw = 1.0f)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

extern "C" int func_001E87B8(void* params, const char* name);
extern "C" int func_001E84E8(void* params, const char* name, void* out, int req);
extern "C" int func_001E7FA8(void* params, unsigned int name, Vec_001A4478* out, int req);
extern "C" int func_001E8118(void* params, const char* name, float* a, float* b, int req);
extern "C" const char* func_001E61F0(unsigned int name);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" int func_00100030(int range);
extern "C" unsigned int func_0010FC30();
extern "C" float func_00341068(float x);
extern unsigned int D_0038C6D4;
extern char D_0038CD60[];
extern char D_00362578[];
extern char D_0038CD68[];
extern char D_0038CD70[];
extern char D_00362588[];
extern char D_003625A0[];
extern char D_003625B0[];
extern char D_003625C0[];

struct C_001A4478 {
    int m_pad[7];
    int m1C;
    unsigned int m20;
    int m24;
    int m28[2];
    Vec_001A4478 m30;
    float m40;
    float m44;
    float m48;
    float m4C;
    float m50;
    int m54;
    int m58;
    int m5C;
    int m60;
    void Init(void* params);
};

void C_001A4478::Init(void* params)
{
    m20 = D_0038C6D4;
    m1C = 0;
    m24 = 0;
    m30.Set(0.0f, 0.0f, 0.0f);
    if (func_001E87B8(params, D_0038CD60)) {
        m60 = 0;
        return;
    }
    m60 = 1;
    func_001E84E8(params, D_00362578, &m1C, 0);
    func_001E7FA8(params, 0, &m30, 0);
    func_001E84E8(params, D_0038CD68, &m20, 0);
    func_001E84E8(params, D_0038CD70, &m24, 0);
    func_00103F28(D_00362588, func_001E61F0(m20));
    m5C = func_001E87B8(params, D_003625A0);
    m58 = 0;
    m44 = 1.0f;
    m48 = 1.0f;
    if (func_001E8118(params, D_003625B0, &m44, &m48, 0)) m58 = 1;
    m4C = 0.0f;
    m50 = 0.0f;
    if (func_001E8118(params, D_003625C0, &m4C, &m50, 0)) m58 = 1;
    m54 = func_00100030(0x400);
    unsigned int t = func_0010FC30() + m54;
    t &= 0x3FF;
    float s = func_00341068(m4C * t * 2.0f * 0.003067961428f);
    float c = func_00341068(m50 * t * 2.0f * 0.003067961428f);
    m40 = m44 + (s * c + 1.0f) * (m48 - m44) * 0.5f;
}
