struct Mgr_0021F4A0 {
    char pad[0x24];
    void* m24;
};
extern Mgr_0021F4A0* D_0038FC78;
extern char D_0038F870[];
extern "C" bool func_001E88F8(void* params, char* name, int* out, int required);
extern "C" void func_002639A0(void* p, int v, int a);

extern "C" bool func_0021F4A0(void* params, void* script)
{
    int v;
    func_001E88F8(params, D_0038F870, &v, 1);
    func_002639A0(D_0038FC78->m24, v, -1);
    return true;
}
