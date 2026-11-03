struct Obj_002D4CF8 {
    int m0;
    int m4;
    int m8;
    char padC[0x1C - 0xC];
    unsigned int m1C;
    char m20[0x3BC - 0x20];
    unsigned int m3BC;
    unsigned int m3C0;
    unsigned int m3C4;
    unsigned int m3C8;
};

struct Thread_002D4CF8 {
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

extern void* D_00392068;

extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" unsigned int func_0010FC30();
extern "C" void func_002D4F90();
extern "C" int func_002A84B8(void* m);
extern "C" void func_00106038(Thread_002D4CF8* t);
extern "C" void func_002A84C0(void* m, int v);
extern "C" void* func_002A84D0(void* m);
extern "C" int func_0031BAC0(void* p, Obj_002D4CF8* o);

void func_002D4CF8(Obj_002D4CF8* p, char* msg)
{
    Thread_002D4CF8 t;
    void* m = D_00392068;
    func_003331D0(p->m20, msg);
    p->m8 = 0;
    p->m1C = func_0010FC30();
    t.m24 = 10;
    p->m3C0 = 0x0089990F;
    p->m3BC = 0x7335AB7F;
    p->m3C8 = 0xCF040665;
    p->m3C4 = 0x4B85EE64;
    t.m18 = func_002D4F90;
    t.m1C = func_002A84B8(m);
    t.m20 = 0x8000;
    t.m10 = 0x152;
    func_00106038(&t);
    func_002A84C0(m, t.m14);
    func_0031BAC0(func_002A84D0(m), p);
}
