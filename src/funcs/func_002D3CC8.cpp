struct Pool_002D3CC8 {
    char pad[0x104];
    int m104;
};

extern Pool_002D3CC8* D_00388A70;
extern "C" void func_0010A950(Pool_002D3CC8* p, int v);
extern "C" void func_0010A9B0(Pool_002D3CC8* p);
extern "C" void func_001048F0(void* p);
extern "C" void func_00305C98(void* p);

struct Obj_002D3CC8 {
    char pad0[0x158];
    void* m158;
    char pad15C[4];
    void* m160;
    void* m164;
    void* m168;
    void Free();
};

void Obj_002D3CC8::Free()
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    func_001048F0(m160);
    func_001048F0(m164);
    func_001048F0(m168);
    if (m158)
        func_00305C98(m158);
    m158 = 0;
    func_0010A9B0(D_00388A70);
}
