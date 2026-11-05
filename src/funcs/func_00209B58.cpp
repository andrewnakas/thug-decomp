extern void* D_0038EEC8;

struct Obj_00209B58;
extern "C" void func_001D3470(Obj_00209B58* o, void* a, void* b);

struct Obj_00209B58 {
    char pad0[0x30];
    char m30[0x2050 - 0x30];
    void* m2050;
    void Run();
};

void Obj_00209B58::Run()
{
    func_001D3470(this, m30, m2050 ? m2050 : D_0038EEC8);
}
