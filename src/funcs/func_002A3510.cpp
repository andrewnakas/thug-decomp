struct Msg_002A3510 {
    unsigned char type;
    char pad[0x1F];
};

extern char D_003783D8[];
extern "C" void func_001FA800(Msg_002A3510* m);
extern "C" void func_00200C00(void* w, Msg_002A3510* m);
extern "C" void func_002010D0(void* w, int a);
extern "C" void func_001048F0(void* p);
extern "C" int func_002D7EB8(void* p);
extern "C" int func_001E54B8(char* name, int a);
extern "C" int func_002D30A8(void* p);
extern "C" void func_002D8248(void* p, int a, int b, int c);

struct Obj_002A3510;
extern "C" int func_002A8258(Obj_002A3510* o);
extern "C" void* func_002A39E0(Obj_002A3510* o, int a);
extern "C" void func_002A3870(Obj_002A3510* o);
extern "C" void func_0029F6C8(Obj_002A3510* o);

struct Obj_002A3510 {
    int m0;
    void* m4;
    int m8;
    void* mC;
    char pad[0x94 - 0x10];
    void* m94;
    void Stop();
};

void Obj_002A3510::Stop()
{
    Msg_002A3510 msg;
    func_001FA800(&msg);
    if (func_002A8258(this) == 9)
        return;
    if (func_002A8258(this) == 7)
        return;
    if (func_002A8258(this) == 8)
        return;
    void* w = func_002A39E0(this, 0);
    msg.type = 11;
    func_00200C00(w, &msg);
    func_002010D0(w, 0);
    func_002A3870(this);
    func_001048F0(m94);
    func_0029F6C8(this);
    if (func_002D7EB8(mC)) {
        int a = func_001E54B8(D_003783D8, 0);
        func_002D8248(mC, 4, a, func_002D30A8(m4));
    }
}
