struct Goal_0024E470 {
    char pad[0x20];
    void* m_params;
};

extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E77D0(void* params, unsigned int name, void* value);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_00244620(Goal_0024E470* goal);

void func_0024E470(Goal_0024E470* goal)
{
    func_001E6B90(goal->m_params, 0x735AF2DD);
    void* p = func_001E6978(func_001190D0(8));
    func_001E77D0(goal->m_params, 0x735AF2DD, p);
    if (p)
        func_001E6AE8(p, 3);
    func_001E7200(goal->m_params, 0xF1E59083, 0);
    func_001E7200(goal->m_params, 0x129DAA10, 0);
    int v;
    func_001E7DE8(goal->m_params, 0xE75C4BBF, &v, 1);
    func_00244620(goal);
}
