struct Obj_002D35B0_A {
    char pad0[0x104];
    int m104;
};

struct Obj_002D35B0_S {
    char pad0[0x13C];
    int m13C;
    char pad140[0x158 - 0x140];
    void* m158;
};

struct Obj_002D35B0_M {
    char pad0[0x4];
    Obj_002D35B0_S* m4;
    char pad8[0x4];
    void* mC;
};

extern Obj_002D35B0_A* D_00388A70;
extern Obj_002D35B0_M* D_00392068;
extern char D_0037BD00[];
extern char D_0037BD18[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_00306428(void* p, int a, int b);
extern "C" int func_002D7EB8(void* p);
extern "C" int func_001E8618(void* p, unsigned int key);
extern "C" void* func_001E54B8(char* s, int v);
extern "C" void func_002D8248(void* p, int v, void* a, void* b);
extern "C" int func_002D3060(Obj_002D35B0_S* s);
extern "C" void func_00306380(void* p, int v);

int func_002D35B0(void* params)
{
    Obj_002D35B0_M* m = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m104);
    Obj_002D35B0_S* s = m->m4;
    void* t = m->mC;
    func_00306428(s->m158, 1, 0);
    s->m13C = 0;
    if (func_002D7EB8(t) && !func_001E8618(params, 0xB2AB4DAB)) {
        void* a = func_001E54B8(D_0037BD00, 0);
        func_002D8248(t, 1, a, func_001E54B8(D_0037BD18, 0));
    }
    func_00306380(s->m158, func_002D3060(s));
    func_0010A9B0(D_00388A70);
    return 1;
}
