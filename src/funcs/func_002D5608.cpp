struct Obj_002D5608_A {
    char pad0[0x108];
    int m108;
};

struct Req_002D5608 {
    int m0;
    char m4[0x100];
    void (*m104)();
    unsigned int m108;
    unsigned int m10C;
    unsigned int m110;
    unsigned int m114;
};

struct Obj_002D5608_S {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x14 - 0x10];
    int m14;
    char pad18[0x1C - 0x18];
    unsigned int m1C;
    char pad20[0x320 - 0x20];
    void* m320;
    char pad324[0x3BC - 0x324];
    unsigned int m3BC;
    unsigned int m3C0;
    unsigned int m3C4;
    unsigned int m3C8;
    void (*m3CC)();
};

struct Obj_002D5608_M {
    char pad0[0x8];
    Obj_002D5608_S* m8;
};

struct Thread_002D5608 {
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

extern Obj_002D5608_A* D_00388A70;
extern Obj_002D5608_M* D_00392068;
extern char* D_0038C308;

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_00105260(void* p, int v);
extern "C" unsigned int func_0010FC30();
extern "C" void func_002D5458();
extern "C" int func_002A84B8(void* m);
extern "C" void func_00106038(Thread_002D5608* t);
extern "C" void func_002A84C0(void* m, int v);
extern "C" int func_0031BAC0(void* p, char* msg);
extern "C" void* func_002A84D0(void* m);
extern "C" void func_0031BCE0(void* p);
extern "C" void func_0031BCC0(void* p);

void func_002D5608(void* self, Req_002D5608* req)
{
    Thread_002D5608 t;
    Obj_002D5608_M* m = D_00392068;
    char* q = D_0038C308;
    func_0010A950(D_00388A70, D_00388A70->m108);
    Obj_002D5608_S* s = m->m8;
    s->mC = 0;
    s->m4 = 3;
    func_00105260(q + 8, s->m0);
    s->m8 = 0;
    s->m1C = func_0010FC30();
    s->m14 = req->m0;
    s->m3BC = req->m108;
    s->m3C0 = req->m10C;
    s->m3C4 = req->m110;
    s->m3C8 = req->m114;
    s->m3CC = req->m104;
    t.m18 = func_002D5458;
    t.m24 = 10;
    t.m1C = func_002A84B8(m);
    t.m20 = 0x8000;
    t.m10 = 0x152;
    func_00106038(&t);
    func_002A84C0(m, t.m14);
    func_0031BCE0(s->m320);
    func_0031BAC0(func_002A84D0(m), req->m4);
    func_0031BCC0(s->m320);
    func_0010A9B0(D_00388A70);
}
