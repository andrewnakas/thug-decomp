struct Obj_002D9378_A {
    char pad0[0x108];
    int m108;
};

struct Obj_002D9378 {
    void* m0;
    int m4;
    int m8;
    void* mC;
};

struct Thread_002D9378 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    void (*m18)();
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
};

extern Obj_002D9378_A* D_00388A70;
extern void* D_00392068;
extern char* D_0038C308;
extern unsigned int D_00392E50;
extern char D_0037C7C8[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" unsigned int func_0010FC30();
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" void func_002D9030();
extern "C" int func_002A84B8(void* m);
extern "C" void func_00106038(Thread_002D9378* t);
extern "C" void func_002A84C0(void* m, int v);
extern "C" void* func_002A84D0(void* m);
extern "C" int func_0031BAC0(void* p, Obj_002D9378* o);
extern "C" int func_00104968(void* p);
extern "C" void func_00105260(void* p, void* q);

void func_002D9378(Obj_002D9378* p)
{
    Thread_002D9378 t;
    void* m = D_00392068;
    char* q = D_0038C308;
    func_0010A950(D_00388A70, D_00388A70->m108);
    p->m8 = 1;
    D_00392E50 = func_0010FC30();
    func_001F0370(D_0037C7C8, 0, 0, 0);
    t.m24 = 10;
    t.m18 = func_002D9030;
    t.m1C = func_002A84B8(m);
    t.m20 = 0x8000;
    t.m10 = 0x152;
    func_00106038(&t);
    func_002A84C0(m, t.m14);
    func_0031BAC0(func_002A84D0(m), p);
    if (func_00104968(p->m0) == 0) {
        func_00105260(q + 8, p->m0);
    }
    func_0010A9B0(D_00388A70);
}
