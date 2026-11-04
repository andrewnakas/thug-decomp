extern char D_00371C78[];

struct Iter_002A8630 {
    int m0;
    int m4;
    void* m8;
    Iter_002A8630() { m4 = 0; m8 = D_00371C78; }
    ~Iter_002A8630() { m8 = D_00371C78; }
};

struct Data_002A8630 {
    int m0;
    char m4;
};

struct Msg_002A8630 {
    unsigned char type;
    char pad1;
    short size;
    Data_002A8630* data;
    char pad8[4];
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

extern "C" void func_001FA800(Msg_002A8630* m);
extern "C" void* func_002A39D8(void* m);
extern "C" int func_002B1FC8(void* item);
extern "C" int func_002B3080(void* item);
extern "C" void func_001FF970(void* q, int id, Msg_002A8630* m);

struct Obj_002A8630;
extern "C" void* func_002A53F8(Obj_002A8630* self, Iter_002A8630* it, int a);
extern "C" void* func_002A5490(Obj_002A8630* self, Iter_002A8630* it, int a);

struct Obj_002A8630 {
    char pad[0x16C];
    unsigned int m16C;
    void Toggle(char bit, int v);
};

void Obj_002A8630::Toggle(char bit, int v)
{
    Data_002A8630 d;
    Msg_002A8630 msg;
    func_001FA800(&msg);
    msg.size = 8;
    Iter_002A8630 it;
    m16C ^= 1 << bit;
    d.m4 = bit;
    d.m0 = v;
    msg.data = &d;
    msg.type = 0x70;
    msg.mC = 2;
    msg.m10 = 8;
    void* q = func_002A39D8(this);
    void* e = func_002A53F8(this, &it, 1);
    if (e) do {
        if (!func_002B1FC8(e))
            func_001FF970(q, func_002B3080(e), &msg);
        e = func_002A5490(this, &it, 1);
    } while (e);
}
