extern "C" int func_001E7EB0(void* params, int name, float* out, int req);

struct Cfg_001456C0 {
    float m_0;
    bool Read(void* params);
};

bool Cfg_001456C0::Read(void* params)
{
    m_0 = 2000.0f;
    func_001E7EB0(params, 0, &m_0, 0);
    return true;
}
