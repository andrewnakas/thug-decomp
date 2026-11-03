extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" float func_001E5318(unsigned int name, int flag);
extern "C" int func_001E5628(unsigned int name, int flag);
extern "C" void func_001E93D0(void* params, int a);

struct C_001A9BC8 {
    int m_pad[7];
    int m1C;
    float m20;
    float m24;
    int m28[5];
    float m3C;
    float m40;
    float m44;
    float m48;
    void Init(void* params);
};

void C_001A9BC8::Init(void* params)
{
    if (func_001E7EB0(params, 0xE4279BA2, &m20, 0)) {
        if (m20 == 0.0f && !func_001E7EB0(params, 0x4EEDFAE7, &m20, 0))
            m20 = func_001E5318(0xAD501995, 0);
        m1C = 0;
        m20 *= 12.0f;
        m24 = m20 * m20;
    }
    if (func_001E8708(params, 0xCB839DC1)) m1C = 1;
    if (func_001E5628(0x95EDC6F6, 0)) {
        m3C = 1000000.0f;
        m40 = 1000001.0f;
        m44 = 1000002.0f;
        m48 = 1000003.0f;
        return;
    }
    m3C = 50.0f;
    m44 = 1000001.0f;
    m48 = 1000002.0f;
    func_001E7EB0(params, 0x4EEDFAE7, &m3C, 0);
    m40 = m3C + 75.0f;
    func_001E7EB0(params, 0xD7E4AB5D, &m40, 0);
    func_001E7EB0(params, 0xA0E39BCB, &m44, 0);
    func_001E7EB0(params, 0x3E870E68, &m48, 0);
    m3C *= 12.0f;
    m40 *= 12.0f;
    m44 *= 12.0f;
    m48 *= 12.0f;
    if (m40 <= m3C) func_001E93D0(params, 0);
    if (m40 >= m44) func_001E93D0(params, 0);
    if (m44 >= m48) func_001E93D0(params, 0);
}
