extern char D_00371C78[];
extern char D_0037C908[];
extern char D_0037C918[];
extern char D_0037C928[];
extern char D_0037C938[];
extern char D_0037C948[];
extern char D_0037C958[];
extern char D_0037C968[];
extern char D_0037C978[];
extern char D_0037C988[];
extern char D_0037C998[];
extern char D_00392E88[];
extern char D_00392E90[];
extern char D_00392E98[];
extern char D_00392EA0[];
extern char D_00392EA8[];
extern char D_00392EB0[];

struct Pool_002D9B18 {
    char pad[0x108];
    int m108;
};
extern Pool_002D9B18* D_00388A70;

struct IterA_002D9B18 {
    int m0;
    int m4;
    void* m8;
    IterA_002D9B18() { m8 = D_00371C78; m4 = 0; }
    ~IterA_002D9B18() { m8 = D_00371C78; }
};

struct Msg_002D9B18 {
    unsigned char m_type;
    unsigned char m_1;
    unsigned short m_size;
    void* m_data;
    int m_8;
    int m_C;
    unsigned char m_10;
    int m_14;
    int m_18;
    int m_1C;
};

struct Info_002D9B18 {
    char pad[0x18];
    int m18;
};

struct Elem_002D9B18 {
    char pad[0x18];
    Info_002D9B18* m18;
    char pad2[0xC];
    int m28;
    char pad3[8];
    char m34[4];
};

struct Mgr_002D9B18;
extern Mgr_002D9B18* D_00392068;

struct Tbl_002D9B18 {
    int (*SetInt)(void* d, char* name, int ctx, int v, int id);
    void* m4;
    int (*SetStr)(void* d, char* name, int ctx, char* v, int id);
    void* mC;
    void* m10;
    void* m14;
    int (*SetInt2)(void* d, char* name, int ctx, int v, int id);
    void* m1C;
    int (*SetStr2)(void* d, char* name, int ctx, char* v, int id);
};
extern Tbl_002D9B18 D_00355DE0;
struct Ctx_002D9B18 {
    int m0;
    int pad[7];
};
extern Ctx_002D9B18 D_00355DC0;

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_002F1DF0(int a);
extern "C" char* func_002F1D98(void* d);
extern "C" void* func_002A39D8(Mgr_002D9B18* m);
extern "C" void* func_002A6070(Mgr_002D9B18* m);
extern "C" int func_001F0D78(char* name);
extern "C" void* func_00202EF8(void* mgr, int id);
extern "C" int func_001E8890(void* obj, char* name, char** out, int flag);
extern "C" int func_00202FC8(void* mgr, int a, int b);
extern "C" char* func_002A22D0(Mgr_002D9B18* m, int v);
extern "C" char* func_002A23F0(Mgr_002D9B18* m);
extern "C" int func_002A58C0(Mgr_002D9B18* m);
extern "C" int func_002A7668(Mgr_002D9B18* m);
extern "C" int func_002A1B30(Mgr_002D9B18* m);
extern "C" Elem_002D9B18* func_002A53F8(Mgr_002D9B18* m, IterA_002D9B18* it, int a);
extern "C" Elem_002D9B18* func_002A5490(Mgr_002D9B18* m, IterA_002D9B18* it, int a);
extern "C" void* func_001FA800(Msg_002D9B18* m);
extern "C" void func_002F21D8(void* d, int id, char* name);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_00331BB8(const char* s);
extern "C" int func_002B3080(Elem_002D9B18* e);
extern "C" void func_001FF970(void* q, int id, Msg_002D9B18* m);

struct Obj_002D9B18 {
    char pad[0xC];
    void* mC;
    void Build();
};

void Obj_002D9B18::Build()
{
    IterA_002D9B18 it;
    Mgr_002D9B18* m = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m108);
    mC = func_002F1DF0(1);
    char* data = func_002F1D98(mC);
    void* q = func_002A39D8(m);
    void* mgr = func_002A6070(m);
    char* level;
    func_001E8890(func_00202EF8(mgr, func_001F0D78(D_0037C908)), D_0037C918, &level, 1);
    int a = func_00202FC8(mgr, func_001F0D78(D_0037C928), func_001F0D78(D_00392E88));
    int b = func_00202FC8(mgr, func_001F0D78(D_0037C938), func_001F0D78(D_00392E90));
    D_00355DE0.SetStr(mC, D_0037C948, D_00355DC0.m0, level, 0);
    D_00355DE0.SetStr(mC, D_00392E98, D_00355DC0.m0, func_002A22D0(m, 1), 0);
    D_00355DE0.SetStr(mC, D_0037C958, D_00355DC0.m0, func_002A23F0(m), 0);
    D_00355DE0.SetInt(mC, D_00392EA0, D_00355DC0.m0, func_002A58C0(m), 0);
    D_00355DE0.SetInt(mC, D_0037C968, D_00355DC0.m0, func_002A7668(m), 0);
    D_00355DE0.SetInt(mC, D_0037C978, D_00355DC0.m0, func_002A1B30(m), 0);
    D_00355DE0.SetInt(mC, D_0037C988, D_00355DC0.m0, a, 0);
    D_00355DE0.SetInt(mC, D_0037C998, D_00355DC0.m0, b, 0);
    for (Elem_002D9B18* e = func_002A53F8(m, &it, 0); e; e = func_002A5490(m, &it, 0)) {
        char buf[0x40];
        Msg_002D9B18 msg;
        func_001FA800(&msg);
        int id = e->m18->m18;
        func_002F21D8(mC, id, e->m34);
        func_003331D0(buf, D_00392EA8);
        D_00355DE0.SetStr2(mC, buf, D_00355DC0.m0, e->m34, id);
        func_003331D0(buf, D_00392EB0);
        D_00355DE0.SetInt2(mC, buf, D_00355DC0.m0, e->m28, id);
        if (e->m28 > 0) {
            msg.m_data = data;
            msg.m_size = func_00331BB8(data) + 1;
            msg.m_type = 0x7C;
            msg.m_C = 2;
            msg.m_10 = 8;
            func_001FF970(q, func_002B3080(e), &msg);
        }
    }
    func_0010A9B0(D_00388A70);
}
