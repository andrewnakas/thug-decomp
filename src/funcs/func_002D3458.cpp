struct Obj_002D3458_A {
    char pad0[0x104];
    int m104;
};

struct Obj_002D3458_E {
    char pad0[0x18];
    char m18[0x58 - 0x18];
    int m58;
    int m5C;
    int m60;
    char pad64[0x74 - 0x64];
    int m74;
};

struct Obj_002D3458_S {
    char pad0[0x158];
    void* m158;
};

struct Obj_002D3458_M {
    char pad0[0x4];
    Obj_002D3458_S* m4;
};

extern Obj_002D3458_A* D_00388A70;
extern Obj_002D3458_M* D_00392068;
extern char D_00392B28[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_001F0D78(char* s);
extern "C" int func_001E7DE8(void* p, int key, int* out, int v);
extern "C" Obj_002D3458_E* func_002D2FB8(Obj_002D3458_S* s, int v);
extern "C" void func_002D3058(Obj_002D3458_S* s, int v);
extern "C" void func_002D3068(Obj_002D3458_S* s, int v);
extern "C" void func_002D3078(Obj_002D3458_S* s, int v);
extern "C" void func_002D3088(Obj_002D3458_S* s, char* v);
extern "C" void func_002D30D8(Obj_002D3458_S* s, int v);
extern "C" int func_002D3060(Obj_002D3458_S* s);
extern "C" void func_002D2530();
extern "C" void func_00306130(void* p, int v, void (*cb)(), void* arg, int w);
extern "C" void func_002D2DB8(Obj_002D3458_S* s);

int func_002D3458(void* params)
{
    int v = 0;
    Obj_002D3458_M* m = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m104);
    func_001E7DE8(params, func_001F0D78(D_00392B28), &v, 0);
    Obj_002D3458_E* e = func_002D2FB8(m->m4, v);
    func_002D3058(m->m4, e->m58);
    func_002D3068(m->m4, e->m5C);
    func_002D3078(m->m4, e->m60);
    func_002D3088(m->m4, e->m18);
    func_002D30D8(m->m4, e->m74);
    Obj_002D3458_S* s = m->m4;
    func_00306130(s->m158, func_002D3060(s), func_002D2530, m->m4, 0);
    func_002D2DB8(m->m4);
    func_0010A9B0(D_00388A70);
    return 1;
}
