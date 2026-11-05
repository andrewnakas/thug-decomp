struct Heap_0022F488 {
    char pad[0xDC];
    int m_DC;
};

extern Heap_0022F488* D_00388A70;
extern void* D_0038FC78;
extern "C" void func_0010A950(Heap_0022F488* heap, int ctx);
extern "C" void func_0010A9B0(Heap_0022F488* heap);
extern "C" void func_0022E9B8(void* self);

bool Cmd_0022F488(void* params, void* script)
{
    void* mgr = D_0038FC78;
    func_0010A950(D_00388A70, D_00388A70->m_DC);
    func_0022E9B8(mgr);
    func_0010A9B0(D_00388A70);
    return true;
}
