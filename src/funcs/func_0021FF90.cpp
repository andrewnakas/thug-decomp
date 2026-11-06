struct Mgr_0021FF90 {
    char m_pad0[0x394];
    void* m394;
};

struct Heap_0021FF90 {
    char m_pad0[0x3EC];
    void* m3EC;
};

extern Mgr_0021FF90* D_0038FC78;
extern Heap_0021FF90* D_00388A70;
extern "C" void* func_0022DD38(void* p);
extern "C" void* func_00203360(void* p);
extern "C" int func_002392B8(void* p);
extern "C" void func_0010A950(Heap_0021FF90* h, void* ctx);
extern "C" void func_00251358(void* p, int v);
extern "C" void func_00251DD8(void* p);
extern "C" void func_0010A9B0(Heap_0021FF90* h);

bool Cmd_0021FF90(void* params, void* script)
{
    int v = func_002392B8(func_00203360(func_0022DD38(D_0038FC78)));
    func_0010A950(D_00388A70, D_00388A70->m3EC);
    func_00251358(D_0038FC78->m394, v);
    func_00251DD8(D_0038FC78->m394);
    func_0010A9B0(D_00388A70);
    return true;
}
