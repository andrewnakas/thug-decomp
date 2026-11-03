struct Obj_002D50B8_A {
    char pad0[0x108];
    int m108;
};

struct Obj_002D50B8 {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x1C - 0x10];
    unsigned int m1C;
    char pad20[0x320 - 0x20];
    void* m320;
    char pad324[0x3BC - 0x324];
    unsigned int m3BC;
    unsigned int m3C0;
    unsigned int m3C4;
    unsigned int m3C8;
};

struct Thread_002D50B8 {
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

extern Obj_002D50B8_A* D_00388A70;
extern void* D_00392068;
extern char* D_0038C308;
extern char D_0037BFC8[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_00105260(void* p, int v);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" unsigned int func_0010FC30();
extern "C" void func_002D5520();
extern "C" int func_002A84B8(void* m);
extern "C" void func_00106038(Thread_002D50B8* t);
extern "C" void func_002A84C0(void* m, int v);
extern "C" void* func_002A84D0(void* m);
extern "C" int func_0031BAC0(void* p, char* msg);
extern "C" void func_0031BCE0(void* p);
extern "C" void func_0031BCC0(void* p);

void func_002D50B8(Obj_002D50B8* p, char* msg)
{
    Thread_002D50B8 t;
    char buf[256];
    void* m = D_00392068;
    char* q = D_0038C308;
    func_0010A950(D_00388A70, D_00388A70->m108);
    p->mC = 0;
    p->m4 = 6;
    func_00105260(q + 8, p->m0);
    p->m8 = 0;
    p->m1C = func_0010FC30();
    t.m24 = 10;
    p->m3C0 = 0x1D53D27F;
    p->m3BC = 0x7335AB7F;
    p->m3C8 = 0x609F7535;
    p->m3C4 = 0x4B85EE64;
    t.m18 = func_002D5520;
    t.m1C = func_002A84B8(m);
    t.m20 = 0x8000;
    t.m10 = 0x152;
    func_00106038(&t);
    func_002A84C0(m, t.m14);
    func_0031BCE0(p->m320);
    func_003331D0(buf, D_0037BFC8, msg);
    char* b = buf;
    func_0031BAC0(func_002A84D0(m), b);
    func_0031BCC0(p->m320);
    func_0010A9B0(D_00388A70);
}
