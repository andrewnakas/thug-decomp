typedef void (*Cb_002D3B98)();

struct Callbacks_002D3B98 {
    Cb_002D3B98 m0;
    Cb_002D3B98 m4;
    int m8;
    int mC;
    int m10;
    Cb_002D3B98 m14;
    int m18;
    int m1C;
    int m20;
    Cb_002D3B98 m24;
    Cb_002D3B98 m28;
    int m2C;
    Cb_002D3B98 m30;
    int m34;
    Cb_002D3B98 m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    Cb_002D3B98 m4C;
    Cb_002D3B98 m50;
    Cb_002D3B98 m54;
    int m58;
    Cb_002D3B98 m5C;
    Cb_002D3B98 m60;
    Cb_002D3B98 m64;
    Cb_002D3B98 m68;
    Cb_002D3B98 m6C;
    void* m70;
};

struct Obj_002D3B98_A {
    char pad0[0xF4];
    int mF4;
};

struct Obj_002D3B98 {
    char pad0[0x13C];
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    char pad150[0x158 - 0x150];
    void* m158;
};

extern Obj_002D3B98_A* D_00388A70;

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_003315B8(void* p, int v, int n);
extern "C" void* func_00305270(Callbacks_002D3B98* cb);
extern "C" void func_002D0C30();
extern "C" void func_002D0D18();
extern "C" void func_002D0DE8();
extern "C" void func_002D0DF0();
extern "C" void func_002D1170();
extern "C" void func_002D1050();
extern "C" void func_002D16D8();
extern "C" void func_002D16F8();
extern "C" void func_002D1888();
extern "C" void func_002D2028();
extern "C" void func_002D1978();
extern "C" void func_002D1B90();
extern "C" void func_002D1FE0();
extern "C" void func_002D1FD8();
extern "C" void func_002D1E70();

void func_002D3B98(Obj_002D3B98* p)
{
    Callbacks_002D3B98 cb;
    func_0010A950(D_00388A70, D_00388A70->mF4);
    func_003315B8(&cb, 0, sizeof(cb));
    cb.m0 = func_002D0C30;
    cb.m4 = func_002D0D18;
    cb.m14 = func_002D0DE8;
    cb.m24 = func_002D0DF0;
    cb.m28 = func_002D1170;
    cb.m38 = func_002D1050;
    cb.m30 = func_002D16D8;
    cb.m4C = func_002D16F8;
    cb.m68 = func_002D1888;
    cb.m5C = func_002D2028;
    cb.m50 = func_002D1978;
    cb.m54 = func_002D1B90;
    cb.m60 = func_002D1FE0;
    cb.m64 = func_002D1FD8;
    cb.m6C = func_002D1E70;
    cb.m70 = p;
    void* h = func_00305270(&cb);
    p->m140 = 0;
    p->m13C = 0;
    p->m14C = 0;
    p->m144 = 1;
    p->m158 = h;
    func_0010A9B0(D_00388A70);
}
