struct Mgr_0021F690 {
    char pad[0x24];
    void* m24;
};
extern Mgr_0021F690* D_0038FC78;
extern char D_0038F878[];
extern "C" int func_001E88F8(void* params, void* name, int* out, int req);
extern "C" int func_00263D80(void* p, int v);

int func_0021F690(void* params, void* script)
{
    int v;
    func_001E88F8(params, D_0038F878, &v, 1);
    return func_00263D80(D_0038FC78->m24, v);
}
