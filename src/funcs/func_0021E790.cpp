struct Mgr_0021E790 {
    char m_pad0[0x39C];
    void* m39C;
};

struct Heap_0021E790 {
    char m_pad0[0x11C];
    void* m11C;
};

extern int D_00388818;
extern Mgr_0021E790* D_0038FC78;
extern Heap_0021E790* D_00388A70;
extern void* D_0038DB38;
extern "C" bool func_001E8A30(void* params, int name, int* out, int required);
extern "C" bool func_001E8870(void* params, int name, int* out, int required);
extern "C" void func_0025F460(void* p);
extern "C" void func_0010A950(Heap_0021E790* h, void* ctx);
extern "C" bool func_001D0558(void* a, int b, int arg, int c);
extern "C" void func_0010A9B0(Heap_0021E790* h);

bool Cmd_0021E790(void* params, void* script)
{
    if (!D_00388818)
        return false;
    int a;
    int b;
    if (!func_001E8A30(params, 0, &a, 0))
        return false;
    if (!func_001E8870(params, 0, &b, 0))
        return false;
    func_0025F460(D_0038FC78->m39C);
    void* tree = D_0038DB38;
    func_0010A950(D_00388A70, D_00388A70->m11C);
    bool r = func_001D0558(tree, a, b, 0);
    func_0010A9B0(D_00388A70);
    return r;
}
