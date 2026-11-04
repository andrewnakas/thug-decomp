struct Inner_002A3448 {
    unsigned int m0;
    unsigned char m4;
    unsigned char m5;
    unsigned char m6;
};

struct Msg_002A3448 {
    unsigned char type;
    char pad;
    unsigned short m2;
    Inner_002A3448* m4;
    char rest[0x18];
};

extern char* D_0038C308;
extern "C" void func_001FA800(Msg_002A3448* m);
extern "C" void func_00200C00(void* w, Msg_002A3448* m);
extern "C" void func_002010D0(void* w, int a);
extern "C" int func_0010FC30();
extern "C" void func_00105260(void* p, void* a);

struct Obj_002A3448;
extern "C" int func_002A18E0(Obj_002A3448* o);
extern "C" void func_002A8250(Obj_002A3448* o, int v);

struct Obj_002A3448 {
    char pad[0x94];
    void* m94;
    char pad2[0x184 - 0x98];
    int m184;
    void Open(void* w);
};

void Obj_002A3448::Open(void* w)
{
    Inner_002A3448 in;
    Msg_002A3448 msg;
    func_001FA800(&msg);
    char* g = D_0038C308;
    in.m4 = func_002A18E0(this) == 1;
    in.m5 = 1;
    in.m0 = 0x30036;
    msg.m2 = 0x10;
    msg.type = 3;
    in.m6 = 0;
    msg.m4 = &in;
    func_00200C00(w, &msg);
    func_002010D0(w, 0);
    m184 = func_0010FC30();
    func_00105260(g + 8, m94);
    func_002A8250(this, 2);
}
