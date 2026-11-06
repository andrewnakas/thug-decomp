struct Heap_00215028 {
    char pad0[0xDC];
    int mDC;
};

extern Heap_00215028* D_00388A70;
extern void* D_0038FC78;
extern void* D_00392068;
extern "C" void func_0010A950(Heap_00215028* h, int a);
extern "C" void func_00235440(void* mgr);
extern "C" bool func_002A1A28(void* net);
extern "C" void func_002A1A18(void* net);
extern "C" void func_0010A9B0(Heap_00215028* h);

bool Cmd_00215028(void* params, void* script)
{
    void* mgr = D_0038FC78;
    void* net = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->mDC);
    func_00235440(mgr);
    if (!func_002A1A28(net))
        func_002A1A18(net);
    func_0010A9B0(D_00388A70);
    return true;
}
