struct Obj_002D9030_A {
    char pad0[0x108];
    int m108;
};

struct Obj_002D9030_C {
    char pad0[0x8];
    int m8;
};

struct Obj_002D9030_B {
    char pad0[0x10];
    Obj_002D9030_C* m10;
};

extern Obj_002D9030_A* D_00388A70;
extern Obj_002D9030_B* D_00392068;
extern char D_00355B30[];
extern char D_00355C30[];
extern char D_0037C790[];
extern char D_00392E70[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_003267F8();
extern "C" void func_00326938();
extern "C" void func_003331D0(void* a, void* b);
extern "C" int func_002F1BF8(int id);

void func_002D9030()
{
    Obj_002D9030_B* mgr = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m108);
    func_003267F8();
    func_003331D0(D_00355B30, D_0037C790);
    func_003331D0(D_00355C30, D_00392E70);
    switch (func_002F1BF8(0x141E)) {
    case 2: mgr->m10->m8 = 3; break;
    case 1: mgr->m10->m8 = 3; break;
    case 3: mgr->m10->m8 = 3; break;
    case 5: mgr->m10->m8 = 3; break;
    case 0: mgr->m10->m8 = 2; break;
    case 4: break;
    }
    func_00326938();
    func_0010A9B0(D_00388A70);
}
