extern "C" int func_001E7EB0(void* params, int name, float* out, int req);

struct Cfg_00145928 {
    char pad[0x18];
    float m_18;
    bool Read(void* params);
};

bool Cfg_00145928::Read(void* params)
{
    m_18 = 0.0f;
    func_001E7EB0(params, 0, &m_18, 0);
    return true;
}
