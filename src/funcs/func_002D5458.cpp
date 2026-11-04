struct Obj_002D5458_A {
    char pad0[0x108];
    int m108;
};

struct Obj_002D5458_S {
    char pad0[0x14];
    int m14;
    void* m18;
    char pad1C[0x320 - 0x1C];
    void* m320;
    void* m324;
    char pad328[0x3CC - 0x328];
    void (*m3CC)();
};

struct Obj_002D5458_M {
    char pad0[0x8];
    Obj_002D5458_S* m8;
};

extern Obj_002D5458_A* D_00388A70;
extern Obj_002D5458_M* D_00392068;

extern "C" void func_0031BCE0(void* p);
extern "C" void func_0031BCC0(void* p);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_003267F8();
extern "C" void func_00326938();
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_002D3FD0();
extern "C" void* func_002E4600(char* name, int a, void* buf, int size, int b, int c, int d,
                                void (*cb1)(), void (*cb2)(), void* arg);

void func_002D5458(char* name)
{
    Obj_002D5458_M* m = D_00392068;
    Obj_002D5458_S* s = m->m8;
    func_0031BCE0(s->m320);
    func_0010A950(D_00388A70, D_00388A70->m108);
    int size = s->m14;
    s->m18 = func_0010A638(D_00388A70, size, 1, 0);
    func_003267F8();
    m->m8->m324 = func_002E4600(name, 0, s->m18, size, 0, 0, 0, func_002D3FD0, s->m3CC, s);
    func_00326938();
    func_0010A9B0(D_00388A70);
    func_0031BCC0(m->m8->m320);
}
