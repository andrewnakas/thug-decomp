struct Obj_002D7E10_A {
    char pad0[0x104];
    int m104;
};

struct Obj_002D7E10 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

extern Obj_002D7E10_A* D_00388A70;
extern char D_0037C560[];
extern char D_0037C578[];
extern char D_0037C590[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" void* func_001E54B8(char* s, int v);
extern "C" void func_002E8DD8(Obj_002D7E10* p, int v, void* a, void* b);

void func_002D7E10(Obj_002D7E10* p, int v)
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    p->m4 = v;
    p->m10 = 1;
    p->m8 = 4;
    func_001F0370(D_0037C560, 0, 0, 0);
    void* a = func_001E54B8(D_0037C578, 0);
    func_002E8DD8(p, 1, a, func_001E54B8(D_0037C590, 0));
    func_0010A9B0(D_00388A70);
}
