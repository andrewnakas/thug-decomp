extern "C" void* func_001E5548(unsigned int id, int flags);
extern "C" int func_001E8180(void* params, unsigned int name, void** out, int req);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E78A8(void* s, unsigned int name, void* sub);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" void func_001840F8(void* obj, void* s);

struct C_001A11F0 {
    int m_pad[3];
    void* mC;
    void Run(unsigned int name);
};

void C_001A11F0::Run(unsigned int name)
{
    void* g = func_001E5548(0x95807202, 1);
    if (!g) return;
    void* sub;
    if (!func_001E8180(g, name, &sub, 0)) return;
    void* s = func_001E6978(func_001190D0(8));
    void* t = func_001E6978(func_001190D0(8));
    func_001E6AC8(t, sub);
    func_001E78A8(s, 0x5DB4115F, t);
    func_001840F8(mC, s);
    if (s) func_001E6AE8(s, 3);
}
