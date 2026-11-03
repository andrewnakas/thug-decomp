struct Obj_002D5520_A {
    char pad0[0x108];
    int m108;
};

struct Obj_002D5520_S {
    char pad0[0x18];
    void* m18;
    char pad1C[0x320 - 0x1C];
    void* m320;
    void* m324;
};

struct Obj_002D5520_M {
    char pad0[0x8];
    Obj_002D5520_S* m8;
};

extern Obj_002D5520_A* D_00388A70;
extern Obj_002D5520_M* D_00392068;

extern "C" void func_0031BCE0(void* p);
extern "C" void func_0031BCC0(void* p);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_003267F8();
extern "C" void func_00326938();
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_002D4118();
extern "C" void func_002D3FD0();
extern "C" void* func_002E4600(char* name, int a, void* buf, int size, int b, int c, int d,
                                void (*cb1)(), void (*cb2)(), void* arg);

void func_002D5520(char* name)
{
    Obj_002D5520_M* m = D_00392068;
    func_0031BCE0(m->m8->m320);
    func_0010A950(D_00388A70, D_00388A70->m108);
    Obj_002D5520_S* s = m->m8;
    s->m18 = func_0010A638(D_00388A70, 0x8000, 1, 0);
    func_003267F8();
    m->m8->m324 = func_002E4600(name, 0, m->m8->m18, 0x8000, 0, 0, 0, func_002D3FD0, func_002D4118, m->m8);
    func_00326938();
    func_0010A9B0(D_00388A70);
    func_0031BCC0(m->m8->m320);
}
