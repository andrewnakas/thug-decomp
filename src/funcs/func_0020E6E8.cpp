extern char D_0038F368[];
extern void* D_0038DB38;

extern "C" bool func_001E8890(void* params, const char* name, const char** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_001D0AA0(void* mgr);
extern "C" void func_001D0708(void* mgr, const char* name, int a, int b, int id, int c, int d, int e);
extern "C" bool func_001D0888(void* mgr, unsigned int crc);
extern "C" void func_001D09B0(void* mgr, const char* name, unsigned int crc, int a);

bool func_0020E6E8(void* params)
{
    void* mgr = D_0038DB38;
    const char* name;
    unsigned int crc;
    func_001E8890(params, D_0038F368, &name, 1);
    func_001E8398(params, 0, &crc, 1);
    func_001D0708(mgr, name, 0, 0, func_001D0AA0(mgr), 0, 0, 0);
    if (!func_001D0888(mgr, crc))
        func_001D09B0(mgr, name, crc, 0);
    return true;
}
