extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_001F0210(unsigned int script, void* params, void* obj, int a, int b);

struct Goal_002463A8 {
    char pad0[0x20];
    void* m_params;

    void AddCount();
};

void Goal_002463A8::AddCount()
{
    int n = 0;
    func_001E7DE8(m_params, 0x129DAA10, &n, 0);
    n++;
    func_001E7200(m_params, 0x129DAA10, n);
    if (func_001E8708(m_params, 0xFD7AE1F4))
        func_001F0210(0xF2E85A34, m_params, 0, 0, 0);
}
