extern "C" int func_001E7EB0(void* params, int name, float* out, int req);

struct Cfg_00145838 {
    char pad[0xC];
    float m_C;
    bool Read(void* params);
};

bool Cfg_00145838::Read(void* params)
{
    m_C = 0.0f;
    func_001E7EB0(params, 0, &m_C, 0);
    return true;
}
