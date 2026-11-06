extern "C" int func_001E7DE8(void* params, int name, int* out, int req);

struct Cfg_00145960 {
    char pad[0x1C];
    int m_1C;
    bool Read(void* params);
};

bool Cfg_00145960::Read(void* params)
{
    m_1C = 8;
    func_001E7DE8(params, 0, &m_1C, 0);
    return true;
}
