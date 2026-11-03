struct Obj_002D4F90_A {
    char pad0[0x108];
    int m108;
};

struct Obj_002D4F90 {
    char pad0[0x18];
    void* m18;
    char pad1C[0x20 - 0x1C];
    char m20[0x320 - 0x20];
    void* m320;
    void* m324;
};

extern Obj_002D4F90_A* D_00388A70;

extern "C" void func_0031BCE0(void* p);
extern "C" void func_0031BCC0(void* p);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_003267F8();
extern "C" void func_00326938();
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_003315B8(void* p, int v, int n);
extern "C" void func_002D41C0();
extern "C" void func_002D3FD0();
extern "C" void* func_002E4600(char* name, int a, void* buf, int size, int b, int c, int d,
                                void (*cb1)(), void (*cb2)(), void* arg);

void func_002D4F90(Obj_002D4F90* p)
{
    func_0031BCE0(p->m320);
    func_0010A950(D_00388A70, D_00388A70->m108);
    func_003267F8();
    func_003315B8(p->m18 = func_0010A638(D_00388A70, 100000, 1, 0), 0, 100000);
    p->m324 = func_002E4600(p->m20, 0, p->m18, 100000, 0, 0, 0, func_002D3FD0, func_002D41C0, p);
    func_00326938();
    func_0010A9B0(D_00388A70);
    func_0031BCC0(p->m320);
}
