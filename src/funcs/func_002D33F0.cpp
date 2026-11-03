struct Obj_002D33F0_A {
    char pad0[0x104];
    int m104;
};

struct Obj_002D33F0_S {
    char pad0[0x158];
    void* m158;
};

struct Obj_002D33F0_M {
    char pad0[0x4];
    Obj_002D33F0_S* m4;
};

extern Obj_002D33F0_A* D_00388A70;
extern Obj_002D33F0_M* D_00392068;

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_002D3060(Obj_002D33F0_S* s);
extern "C" void func_002D2530();
extern "C" void func_00306130(void* p, int v, void (*cb)(), void* arg, int w);

int func_002D33F0()
{
    Obj_002D33F0_M* m = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m104);
    Obj_002D33F0_S* s = m->m4;
    func_00306130(s->m158, func_002D3060(s), func_002D2530, m->m4, 0);
    func_0010A9B0(D_00388A70);
    return 1;
}
