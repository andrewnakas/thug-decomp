struct Pool_002D6958 {
    char pad[0x104];
    int m104;
};

extern Pool_002D6958* D_00388A70;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_002E8BC8(void* p, int v);

extern "C" void func_002D6958(void* self, int* v, void* p)
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    func_002E8BC8(p, *v);
    func_0010A9B0(D_00388A70);
}
