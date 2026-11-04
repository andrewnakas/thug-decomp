extern long D_0038D1C0[];
extern char D_0038D1C8[];
extern char D_0038D1D0[];
extern void* D_0038DB38;
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);

extern "C" int func_001E8870(void* params, unsigned int name, const char** out, int req);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" char* func_003364D8(const char* s, const char* sub);
extern "C" int func_001D0708(void* mgr, const char* name, int a, int b, int c, int d, int e, int f);

struct C_001B7428 {
    char pad[0x1C];
    int m1C;
    void Load(void* params);
};

void C_001B7428::Load(void* params)
{
    const char* model = 0;
    if (!func_001E8870(params, 0x286A8D26, &model, 0))
        return;
    char path[256];
    memcpy(path, D_0038D1C0, 8);
    func_00331678(path, model);
    char* ext = func_003364D8(path, D_0038D1C8);
    if (ext)
        memcpy(ext, D_0038D1D0, 4);
    else
        func_00331678(path, D_0038D1D0);
    m1C = func_001D0708(D_0038DB38, path, 0, 0, 0, 0, 0, 0);
}
