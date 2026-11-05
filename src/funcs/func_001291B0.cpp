extern void* D_0038DB38;
extern void* D_00388A70;
extern "C" void* func_001D0638(void* mgr, unsigned int name, int a);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0011D570(void* p, void* model);
extern "C" void func_0013CC80(void* parent, void* child);

extern "C" void* func_001291B0(void* self, void* parent, unsigned int name)
{
    void* model = func_001D0638(D_0038DB38, name, 0);
    void* inst = func_0011D570(func_0010A638(D_00388A70, 0x1C, 1, 0), model);
    func_0013CC80(parent, inst);
    return inst;
}
