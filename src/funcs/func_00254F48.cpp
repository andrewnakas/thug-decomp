struct Mgr_00254F48 {
    char pad[0x64];
    int m64;
};

extern Mgr_00254F48* D_00390828;
extern char D_00375290[];
extern char D_003752A8[];
extern "C" void func_002540C0(Mgr_00254F48* m, void* params);
extern "C" int func_001E87B8(void* params, const char* name);

bool Cmd_00254F48(void* params, void* script)
{
    Mgr_00254F48* m = D_00390828;
    func_002540C0(m, params);
    if (func_001E87B8(params, D_00375290)) m->m64 = 1;
    else if (func_001E87B8(params, D_003752A8)) m->m64 = 0;
    return true;
}
