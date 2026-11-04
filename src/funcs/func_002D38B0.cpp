struct Obj_002D38B0_A {
    char pad0[0x104];
    int m104;
};

struct Obj_002D38B0_S {
    char pad0[0x158];
    void* m158;
};

struct Obj_002D38B0_M {
    char pad0[0x4];
    Obj_002D38B0_S* m4;
};

extern Obj_002D38B0_A* D_00388A70;
extern Obj_002D38B0_M* D_00392068;
extern char D_00392BC0[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_001E87B8(void* p, char* name);
extern "C" void func_00305FB0(void* p, int v);

int func_002D38B0(void* params)
{
    Obj_002D38B0_M* m = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m104);
    if (func_001E87B8(params, D_00392BC0)) {
        func_00305FB0(m->m4->m158, 0);
    } else {
        func_00305FB0(m->m4->m158, 1);
    }
    func_0010A9B0(D_00388A70);
    return 1;
}
