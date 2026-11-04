struct Pool_002D26C0 {
    char pad[0x104];
    int m104;
};

struct Data_002D26C0 {
    char pad0[0x158];
    void* m158;
};

extern Pool_002D26C0* D_00388A70;
extern "C" void func_0010A950(Pool_002D26C0* p, int v);
extern "C" void func_0010A9B0(Pool_002D26C0* p);
extern "C" void func_00305E50(void* p);

struct Obj_002D26C0 {
    char pad0[0x20];
    Data_002D26C0* m20;
    void Run();
};

void Obj_002D26C0::Run()
{
    Data_002D26C0* d = m20;
    func_0010A950(D_00388A70, D_00388A70->m104);
    func_00305E50(d->m158);
    func_0010A9B0(D_00388A70);
}
