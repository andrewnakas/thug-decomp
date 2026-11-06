extern char D_0035D288[];
extern char D_0035D298[];
struct Mgr_0012F370;
extern Mgr_0012F370* D_00389A30;
extern "C" bool func_001E87B8(void* params, const char* name);
extern "C" void* func_0012E438(Mgr_0012F370* m, void* params, unsigned int name);
extern "C" void func_0012D8B0(Mgr_0012F370* m, void* e, int recurse, int preserve, void* script);

extern "C" bool func_0012F370(void* params, void* script)
{
    Mgr_0012F370* m = D_00389A30;
    void* e = func_0012E438(m, params, 0x40C698AF);
    int recurse = !func_001E87B8(params, D_0035D288);
    int preserve = func_001E87B8(params, D_0035D298);
    if (!recurse && preserve) {
        return true;
    }
    func_0012D8B0(m, e, recurse, preserve, script);
    return true;
}
