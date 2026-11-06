extern void* D_00388A70;
extern void* D_0038DB38;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_001D0638(void* mgr, void* name, int a);
extern "C" void* func_0011D570(void* mem, void* src);

struct Obj_0019EA00 {
    char pad0[0x1C];
    void* m1C;
    void Fn(void* name);
};

void Obj_0019EA00::Fn(void* name)
{
    void* src = func_001D0638(D_0038DB38, name, 0);
    m1C = func_0011D570(func_0010A638(D_00388A70, 0x1C, 1, 0), src);
}
