extern "C" int func_001E7EB0(void* params, int name, float* out, int req);

struct Cfg_00145998 {
    char pad[0x20];
    float m_20;
    bool Read(void* params);
};

bool Cfg_00145998::Read(void* params)
{
    m_20 = 16.0f;
    func_001E7EB0(params, 0, &m_20, 0);
    return true;
}
