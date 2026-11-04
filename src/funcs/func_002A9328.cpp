extern char D_00371C78[];

struct Iter_002A9328 {
    int m0;
    int m4;
    void* m8;
    Iter_002A9328() { m4 = 0; m8 = D_00371C78; }
    ~Iter_002A9328() { m8 = D_00371C78; }
};

struct Msg_002A9328 {
    unsigned char type;
    char pad1[0xB];
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

extern void* D_00392068;
extern "C" int func_002A1A38(void* s);
extern "C" void func_001FA800(Msg_002A9328* m);
extern "C" void* func_002A39D8(void* m);
extern "C" void* func_002A53F8(void* self, Iter_002A9328* it, int a);
extern "C" void* func_002A5490(void* self, Iter_002A9328* it, int a);
extern "C" int func_002B1FE8(void* item);
extern "C" int func_002B3080(void* item);
extern "C" void func_001FF970(void* q, int id, Msg_002A9328* m);

bool Cmd_002A9328()
{
    Iter_002A9328 it;
    void* mgr = D_00392068;
    if (func_002A1A38(mgr)) {
        Msg_002A9328 msg;
        func_001FA800(&msg);
        void* q = func_002A39D8(mgr);
        msg.type = 0x5A;
        msg.mC = 2;
        msg.m10 = 8;
        void* e = func_002A53F8(mgr, &it, 1);
        if (e) do {
            if (func_002B1FE8(e))
                func_001FF970(q, func_002B3080(e), &msg);
            e = func_002A5490(mgr, &it, 1);
        } while (e);
    }
    return true;
}
