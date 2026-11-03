extern char D_00371C78[];

struct Iter_002A87B0 {
    int m0;
    int m4;
    void* m8;
    Iter_002A87B0() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A87B0() { m8 = D_00371C78; }
};

struct Data_002A87B0 {
    unsigned char m0;
    unsigned char m1;
};

struct Msg_002A87B0 {
    unsigned char type;
    char pad1;
    short size;
    Data_002A87B0* data;
    char pad8[4];
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

extern void* D_00392068;
extern char D_003921A0[];
extern char D_003789D8[];
extern "C" void func_001FA800(Msg_002A87B0* m);
extern "C" void func_001E7E58(void* p, char* name, int* out, int v);
extern "C" void* func_002A52F0(void* self, unsigned short id);
extern "C" void* func_002A39D8(void* m);
extern "C" void* func_002A53F8(void* self, Iter_002A87B0* it, int a);
extern "C" void* func_002A5490(void* self, Iter_002A87B0* it, int a);
extern "C" int func_002B1FC8(void* item);
extern "C" int func_002B3080(void* item);
extern "C" void func_001FF970(void* q, int id, Msg_002A87B0* m);
extern "C" void func_002B2790(void* obj, int v);

bool Cmd_002A87B0(void* params, void* script)
{
    Iter_002A87B0 it;
    Data_002A87B0 d;
    Msg_002A87B0 msg;
    int a;
    int b;
    void* mgr = D_00392068;
    func_001FA800(&msg);
    func_001E7E58(params, D_003921A0, &a, 0);
    func_001E7E58(params, D_003789D8, &b, 0);
    void* sk = func_002A52F0(mgr, a);
    if (!sk) return true;
    d.m0 = a;
    d.m1 = b;
    msg.size = 2;
    msg.type = 0x71;
    msg.data = &d;
    msg.mC = 2;
    msg.m10 = 8;
    void* q = func_002A39D8(mgr);
    void* e = func_002A53F8(mgr, &it, 1);
    if (e) do {
        if (func_002B1FC8(e))
            func_002B2790(sk, b);
        else
            func_001FF970(q, func_002B3080(e), &msg);
        e = func_002A5490(mgr, &it, 1);
    } while (e);
    return true;
}
