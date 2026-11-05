struct Mgr_0021F558 {
    char pad[0x24];
    void* m24;
};
extern Mgr_0021F558* D_0038FC78;
extern char D_0038F878[];
extern char D_00371790[];
extern "C" int func_001E88F8(void* params, void* name, int* out, int req);
extern "C" void func_00263CA0(void* p, int v, int w);
extern "C" void func_001E5648(void* name, int v);

bool func_0021F558(void* params, void* script)
{
    int v;
    func_001E88F8(params, D_0038F878, &v, 1);
    func_00263CA0(D_0038FC78->m24, v, -1);
    func_001E5648(D_00371790, 1);
    return true;
}
