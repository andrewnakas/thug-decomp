struct Msg_002AA940 {
    unsigned char m0;
    char pad1;
    unsigned short m2;
    void* m4;
    int m8;
    int mC;
    unsigned char m10;
    char pad[0xF];
};

struct Prefs_002AA940 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
};

struct Mgr_002AA940 {
    char pad0[0x18C];
    int m18C;
};

extern Mgr_002AA940* D_00392068;
extern char D_00378250[];
extern char D_00378328[];
extern char D_00378B50[];
extern char D_003788F8[];
extern char D_00378908[];
extern char D_003784B0[];
extern char D_00378B68[];
extern char D_003788D0[];
extern char D_003788C0[];
extern "C" void func_001FA800(Msg_002AA940* m);
extern "C" void* func_002A6070(Mgr_002AA940* m);
extern "C" int func_001F0D78(const char* s);
extern "C" int func_00203018(void* p, int a, int b);
extern "C" int func_002A7668(Mgr_002AA940* m);
extern "C" void* func_002A39E0(Mgr_002AA940* m, int v);
extern "C" void func_00200C00(void* conn, Msg_002AA940* m);

bool Cmd_002AA940(void* params, void* script)
{
    Prefs_002AA940 prefs;
    Msg_002AA940 msg;
    func_001FA800(&msg);
    Mgr_002AA940* m = D_00392068;
    void* obj = func_002A6070(m);
    prefs.m8 = func_00203018(obj, func_001F0D78(D_00378250), func_001F0D78(D_00378328));
    prefs.mC = func_00203018(obj, func_001F0D78(D_00378B50), func_001F0D78(D_00378328));
    prefs.m0 = func_002A7668(m);
    prefs.m4 = func_00203018(obj, func_001F0D78(D_003788F8), func_001F0D78(D_00378328));
    prefs.m1C = 0;
    prefs.m1C = func_00203018(obj, func_001F0D78(D_00378908), func_001F0D78(D_00378328));
    prefs.m10 = func_00203018(obj, func_001F0D78(D_003784B0), func_001F0D78(D_00378328));
    prefs.m14 = func_00203018(obj, func_001F0D78(D_00378B68), func_001F0D78(D_00378328));
    prefs.m20 = func_00203018(obj, func_001F0D78(D_003788D0), func_001F0D78(D_00378328));
    prefs.m24 = func_00203018(obj, func_001F0D78(D_003788C0), func_001F0D78(D_00378328));
    void* conn = func_002A39E0(m, 0);
    msg.m2 = 0x28;
    msg.m0 = 0x60;
    msg.mC = 2;
    msg.m10 = 8;
    msg.m4 = &prefs;
    func_00200C00(conn, &msg);
    m->m18C = 1;
    return true;
}
