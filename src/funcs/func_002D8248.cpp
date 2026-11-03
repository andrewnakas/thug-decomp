struct Obj_002D8248_A {
    char pad0[0x104];
    int m104;
};

extern Obj_002D8248_A* D_00388A70;

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_002E8DD8(void* a, void* b, void* c, void* d);

void func_002D8248(void* a, void* b, void* c, void* d)
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    func_002E8DD8(a, b, c, d);
    func_0010A9B0(D_00388A70);
}
