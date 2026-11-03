struct Obj_002D0610_A {
    char pad0[0x104];
    int m104;
};

struct Obj_002D0610 {
    char pad0[0x158];
    void* m158;
};

extern Obj_002D0610_A* D_00388A70;
extern char D_0037B748[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_002D0680(Obj_002D0610* p);
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" void func_002D1580();
extern "C" void func_00306A20(void* p, int v, void (*cb)(), void* arg);

void func_002D0610(Obj_002D0610* p)
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    func_002D0680(p);
    func_001F0370(D_0037B748, 0, 0, 0);
    func_00306A20(p->m158, 1, func_002D1580, p);
    func_0010A9B0(D_00388A70);
}
