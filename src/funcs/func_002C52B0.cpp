struct Obj_002C52B0_A {
    char pad0[0xEC];
    int mEC;
};

struct Obj_002C52B0 {
    char pad0[0xBC];
    void* mBC;
};

extern Obj_002C52B0_A* D_00388A70;
extern void* D_00392940;

extern "C" void* func_002CC830();
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_002CBDC0(void* p, int v);
extern "C" void func_002CBE48(void* p, void* q);

void func_002C52B0(Obj_002C52B0* p)
{
    void* cur = func_002CC830();
    func_0010A950(D_00388A70, D_00388A70->mEC);
    p->mBC = func_002CBDC0(func_0010A638(D_00388A70, 0x108, 1, 0), 0);
    func_002CBE48(p->mBC, cur);
    func_0010A9B0(D_00388A70);
    D_00392940 = cur;
}
