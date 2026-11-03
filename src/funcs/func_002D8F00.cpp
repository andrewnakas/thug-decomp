struct Obj_002D8F00_A {
    char pad0[0x104];
    int m104;
};

struct Obj_002D8F00_S {
    char pad0[0x8];
    int m8;
    char padC[0x4];
    unsigned int m10;
};

struct Obj_002D8F00 {
    char pad0[0x20];
    Obj_002D8F00_S* m20;
    void Update();
};

extern Obj_002D8F00_A* D_00388A70;
extern unsigned int D_00392E50;
extern char D_0037C738[];
extern char D_0037C758[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" unsigned int func_0010FC30();
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" void func_002D9468(Obj_002D8F00_S* s);
extern "C" void func_002D92E8(Obj_002D8F00_S* s);
extern "C" void func_002D9ED0(Obj_002D8F00_S* s, int v);
extern "C" int func_002F25A0();

static inline bool Elapsed(unsigned int ms, unsigned int now, unsigned int start)
{
    return now - start > ms;
}

void Obj_002D8F00::Update()
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    Obj_002D8F00_S* s = m20;
    switch (s->m8) {
    case 0:
        break;
    case 1:
        if (Elapsed(10000, func_0010FC30(), D_00392E50)) {
            func_001F0370(D_0037C738, 0, 0, 0);
            func_002D9468(s);
        }
        break;
    case 2:
        s->m8 = 4;
        func_002D92E8(s);
        break;
    case 3:
        func_001F0370(D_0037C758, 0, 0, 0);
        func_002D9468(s);
        break;
    case 4:
        break;
    case 5:
        if (Elapsed(10000, func_0010FC30(), D_00392E50) || func_002F25A0() == 0) {
            func_001F0370(D_0037C738, 0, 0, 0);
            func_002D9468(s);
        }
        break;
    case 6:
        if (func_0010FC30() - s->m10 > 60000) {
            func_002D9ED0(s, 0);
        }
        break;
    }
    func_0010A9B0(D_00388A70);
}
