extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void func_002BC9E0(void* p);
extern "C" void* func_002C70D0(void* p);
extern "C" void* func_002C9F00(void* p);

struct Obj_002C4C30 {
    char pad0[0x80];
    void* m80;
    char pad84[0x1C];
    void* mA0;
    void* mA4;
    void Setup(int flag);
};

void Obj_002C4C30::Setup(int flag)
{
    func_002BC9E0(m80);
    if (!flag) return;
    if (mA0) return;
    mA0 = func_002C70D0(func_0010A638(D_00388A70, 0xE0, 1, 0));
    mA4 = func_002C9F00(func_0010A638(D_00388A70, 0x1C, 1, 0));
}
