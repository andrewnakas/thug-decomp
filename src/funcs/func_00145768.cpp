extern "C" int func_001E7EB0(void* params, int name, float* out, int req);

struct Cfg_00145768 {
    char pad[0x8];
    float m_8;
    bool Read(void* params);
};

bool Cfg_00145768::Read(void* params)
{
    m_8 = 100.0f;
    func_001E7EB0(params, 0, &m_8, 0);
    return true;
}
