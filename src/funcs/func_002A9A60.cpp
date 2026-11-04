struct Data_002A9A60 {
    unsigned char m0;
    unsigned char m1;
};

struct Msg_002A9A60 {
    unsigned char type;
    char pad1;
    short size;
    Data_002A9A60* data;
    char pad8[4];
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

struct Inner_002A9A60 {
    char pad[0x18];
    int m18;
};

struct Elem_002A9A60 {
    char pad[0x18];
    Inner_002A9A60* m18;
    int GetId() { return m18->m18; }
};

extern void* D_00392068;
extern unsigned int D_003921B8;
extern char D_003921C0[];
extern char D_003921C8[];
extern char D_003921D0[];
extern "C" void func_001FA800(Msg_002A9A60* m);
extern "C" Elem_002A9A60* func_002A56E0(void* m);
extern "C" int func_001E8398(void* p, unsigned int key, int* out, int req);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_002A39E0(void* m, int a);
extern "C" unsigned int func_0010FC30();
extern "C" void func_00200C00(void* w, Msg_002A9A60* m);

bool Cmd_002A9A60(void* params, void* script)
{
    Data_002A9A60 d;
    Msg_002A9A60 msg;
    void* mgr = D_00392068;
    func_001FA800(&msg);
    Elem_002A9A60* e = func_002A56E0(mgr);
    if (!e) return false;
    if (!e->m18) return false;
    int v;
    func_001E8398(params, 0, &v, 0);
    unsigned char mode;
    if (v == func_001F0D78(D_003921C0)) mode = 1;
    else if (v == func_001F0D78(D_003921C8)) mode = 0;
    else if (v == func_001F0D78(D_003921D0)) mode = 2;
    else mode = 3;
    d.m1 = mode;
    d.m0 = e->GetId();
    void* w = func_002A39E0(mgr, 0);
    if (func_0010FC30() - D_003921B8 < 150) return true;
    D_003921B8 = func_0010FC30();
    msg.size = 2;
    msg.type = 0x67;
    msg.data = &d;
    msg.mC = 2;
    msg.m10 = 8;
    func_00200C00(w, &msg);
    return true;
}
