struct Pool_002B3100 {
    char pad0[0x3EC];
    int m3EC;
};

extern Pool_002B3100* D_00388A70;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001046B0(int n);
extern "C" void* func_00261078(void* p);

struct Obj_002B3100 {
    char pad0[0x1C];
    void* m1C;
    char pad20[4];
    int m24;
    char pad28[4];
    int m2C;
    int m30;
    int m34;
    int m38;
    Obj_002B3100();
};

Obj_002B3100::Obj_002B3100()
{
    func_0010A950(D_00388A70, D_00388A70->m3EC);
    m1C = func_00261078(func_001046B0(0x64));
    m24 = 0;
    m2C = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    func_0010A9B0(D_00388A70);
}
