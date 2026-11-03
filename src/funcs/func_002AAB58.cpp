struct Msg_002AAB58 {
    unsigned char type;
    char pad1;
    short size;
    int* data;
    char pad8[4];
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

extern void* D_00392068;
extern char D_00392118[];
extern char D_003781B8[];
extern char D_003781C8[];
extern "C" void func_001FA800(Msg_002AAB58* m);
extern "C" int func_001F0D78(char* s);
extern "C" int func_001E8398(void* p, int key, int* out, int req);
extern "C" void* func_002A39E0(void* m, int a);
extern "C" void* func_002C0368();
extern "C" int func_002BCE20(void* p, int v);
extern "C" void func_00200B30(void* w, int type, int time, int v, char* s, int a, int b, int c);
extern "C" void* func_0029C320();
extern "C" int func_0029A2C8(void* p);
extern "C" void func_00200C00(void* w, Msg_002AAB58* m);

bool Cmd_002AAB58(void* params, void* script)
{
    Msg_002AAB58 msg;
    int v;
    int data;
    void* mgr = D_00392068;
    func_001FA800(&msg);
    v = 0;
    func_001E8398(params, func_001F0D78(D_00392118), &v, 0);
    data = v;
    void* w = func_002A39E0(mgr, 0);
    if (v == (int)0xB664035D) {
        func_00200B30(w, 0x6C, 15000, func_002BCE20(func_002C0368(), 0), D_003781B8, 8, 1, 0);
        func_0029C320();
        func_00200B30(w, 0x88, 0x1132, func_0029A2C8(func_0029C320()), D_003781C8, 8, 1, 0);
    }
    msg.data = &data;
    msg.size = 4;
    msg.type = 0x62;
    msg.mC = 2;
    msg.m10 = 8;
    func_00200C00(w, &msg);
    return true;
}
