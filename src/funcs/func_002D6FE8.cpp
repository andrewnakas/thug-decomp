struct Obj_002D6FE8_A {
    char pad0[0x104];
    int m104;
};

struct Obj_002D6FE8_S {
    char pad0[0x8];
    int m8;
};

struct Obj_002D6FE8 {
    char pad0[0x20];
    Obj_002D6FE8_S* m20;
    void Update();
};

extern Obj_002D6FE8_A* D_00388A70;
extern unsigned int D_00392D88;
extern unsigned int D_00392DBC;
extern char D_0037C2B8[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" unsigned int func_0010FC30();
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" void func_002D7EC0(Obj_002D6FE8_S* s);
extern "C" void func_002D8070(Obj_002D6FE8_S* s);
extern "C" void func_002E87D0(Obj_002D6FE8_S* s);

static inline bool Elapsed(unsigned int ms, unsigned int now, unsigned int start)
{
    return now - start > ms;
}

void Obj_002D6FE8::Update()
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    Obj_002D6FE8_S* s = m20;
    switch (s->m8) {
    case 0:
        break;
    case 3:
        func_002D7EC0(s);
        break;
    case 1:
    case 2:
        if (Elapsed(10000, func_0010FC30(), D_00392D88)) {
            func_002D8070(s);
            func_001F0370(D_0037C2B8, 0, 0, 0);
        } else {
            func_002E87D0(s);
        }
        break;
    case 4:
        if (Elapsed(1000, func_0010FC30(), D_00392DBC)) {
            func_002E87D0(s);
            D_00392DBC = func_0010FC30();
        }
        break;
    }
    func_0010A9B0(D_00388A70);
}
