extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6B30(void* s);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);

struct Comp_0025A9A8 {
    char m_pad[0x1C];
    bool m_1C;
    bool m_20;
    int m_24[2];
    bool m_2C;
    int m_30;
    unsigned int m_34;
    void* m_params;
    void InitFromStructure(void* params);
};

void Comp_0025A9A8::InitFromStructure(void* params)
{
    if (!m_params)
        m_params = func_001E6978(func_001190D0(8));
    func_001E6B30(m_params);
    if (func_001E8398(params, 0x1A005041, &m_34, 0)) {
        void* p = 0;
        if (func_001E8180(params, 0x894FD988, &p, 0))
            func_001E6AC8(m_params, p);
    }
    int a = 0;
    func_001E7DE8(params, 0x8DDE72C0, &a, 0);
    m_20 = a != 0;
    m_1C = func_001E8708(params, 0xEB300C29);
    int b = 0;
    func_001E7DE8(params, 0xB8CA12C5, &b, 0);
    m_2C = b != 0;
}
