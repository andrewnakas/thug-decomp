struct Mgr_00130288;
extern Mgr_00130288* D_00389A30;
extern "C" void* func_0012E438(Mgr_00130288* m, void* params, unsigned int name);
extern "C" void func_0012F1C0(Mgr_00130288* m, void* e);

extern "C" bool func_00130288(void* params)
{
    Mgr_00130288* m = D_00389A30;
    void* e = func_0012E438(m, params, 0x40C698AF);
    if (e) {
        func_0012F1C0(m, e);
        return true;
    }
    return false;
}
