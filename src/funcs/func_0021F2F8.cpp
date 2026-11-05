struct Mgr_0021F2F8 {
    char pad[0x24];
    void* m24;
};
extern Mgr_0021F2F8* D_0038FC78;
extern char D_0038F868[];
extern "C" int func_001E88F8(void* params, void* name, int* out, int req);
extern "C" void func_002638B0(void* p, int v);

bool func_0021F2F8(void* params, void* script)
{
    int v;
    func_001E88F8(params, D_0038F868, &v, 1);
    func_002638B0(D_0038FC78->m24, v);
    return true;
}
