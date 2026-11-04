struct Obj_002D2D40_A {
    char pad0[0x108];
    int m108;
};

struct Obj_002D2D40 {
    char pad0[0x158];
    void* m158;
};

extern Obj_002D2D40_A* D_00388A70;
extern void* D_00392068;
extern int D_00392B10;
extern char D_0037BC90[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_002B5608(void* p, int v);
extern "C" void func_002D22F8();
extern "C" void func_00306528(void* p, char* s, void (*cb)(), void* arg, int w);

void func_002D2D40(Obj_002D2D40* p)
{
    void* m = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m108);
    func_002B5608(m, 11);
    D_00392B10 = 0;
    func_00306528(p->m158, D_0037BC90, func_002D22F8, p, 0);
    func_0010A9B0(D_00388A70);
}
