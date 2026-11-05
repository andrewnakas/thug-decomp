extern void* D_00389520;
extern void* D_00389518;
extern "C" void* func_0011FE18(void* o, unsigned int id);
extern "C" void* func_001200E0(void* o);
extern "C" int func_00123420(void* o);
extern "C" int func_00120158(void* o);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" void func_0013D2F0(void* mgr, const char* name, unsigned int id, int a, int b, int c, bool d);

struct C_00120910 {
    char pad0[0x48];
    int m48;
    int m4C;
    int Load(unsigned int id);
};

int C_00120910::Load(unsigned int id)
{
    void* params = func_0011FE18(D_00389520, id);
    if (!params) return 1;
    int flag = 0;
    func_001E7DE8(params, 0x92B43E79, &flag, 0);
    void* o = func_001200E0(D_00389520);
    if ((o && func_00123420(o)) || func_00120158(D_00389520)) {
        const char* name;
        if (func_001E7C80(params, 0xC9AED80F, &name, 0)) {
            func_0013D2F0(D_00389518, name, id, m48, m4C, 0, flag != 0);
            return 1;
        }
    }
    const char* name;
    if (func_001E7C80(params, 0x1E90C5A9, &name, 0))
        func_0013D2F0(D_00389518, name, id, m48, m4C, 0, flag != 0);
    if (func_001E7C80(params, 0xFECA8BB3, &name, 0))
        func_0013D2F0(D_00389518, name, id, m48, m4C, 0, flag != 0);
    if (func_001E7C80(params, 0x67C3DA09, &name, 0))
        func_0013D2F0(D_00389518, name, id, m48, m4C, 0, flag != 0);
    if (func_001E7C80(params, 0x10C4EA9F, &name, 0))
        func_0013D2F0(D_00389518, name, id, m48, m4C, 0, flag != 0);
    if (func_001E7C80(params, 0x8EA07F3C, &name, 0))
        func_0013D2F0(D_00389518, name, id, m48, m4C, 0, flag != 0);
    return 1;
}
