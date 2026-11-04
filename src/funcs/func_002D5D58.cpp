extern char D_00392C38[];
extern char D_00392D00[];
extern char D_0037C0C0[];
extern char D_0037C0B0[];
extern char D_00392CD8[];
extern char D_00392C98[];
extern char D_00392D08[];
extern char D_0037C060[];
extern char D_0037C070[];
extern char D_0037C080[];
extern char D_00392CA8[];
extern char D_0037C090[];
extern char D_00392CC0[];

struct Conn_002D5D58 {
    void* m0;
    int m4;
    int m8;
    int mC;
    char pad10[0xC];
    unsigned int m1C;
    char pad20[0xA0 - 0x20];
    char mA0[0x80];
    char m120[0x320 - 0x120];
    void* m320;
    char pad324[4];
    int m328;
    int m32C;
    int m330;
    int m334;
    int m338;
    int m33C;
    int m340;
    int m344;
    int m348;
    int m34C;
    char pad350[0x378 - 0x350];
    int m378;
    char pad37C[0x3BC - 0x37C];
    unsigned int m3BC;
};

struct Mgr_002D5D58 {
    char pad[8];
    Conn_002D5D58* m8;
};

struct Thread_002D5D58 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    void (*m18)();
    int m1C;
    int m20;
    int m24;
};

extern Mgr_002D5D58* D_00392068;
extern char* D_0038C308;
extern "C" void func_00105260(void* p, void* q);
extern "C" unsigned int func_0010FC30();
extern "C" int func_001E8A50(void* p, char* key, int* out, int flag);
extern "C" int func_001E81F0(void* p, char* key, int* out, int flag);
extern "C" int func_001E7D18(void* p, char* name, char** out, int v);
extern "C" int func_001E88F8(void* p, char* key, int* out, int flag);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" void func_002D57C8();
extern "C" int func_002A84B8(void* m);
extern "C" void func_00106038(Thread_002D5D58* t);
extern "C" void func_002A84C0(void* m, int v);
extern "C" void func_0031BCE0(void* p);
extern "C" void* func_002A84D0(void* m);
extern "C" int func_0031BAC0(void* p, Conn_002D5D58* o);
extern "C" void func_0031BCC0(void* p);

bool Cmd_002D5D58(void* params)
{
    Thread_002D5D58 t;
    char* a;
    char* b;
    Mgr_002D5D58* m = D_00392068;
    Conn_002D5D58* c = m->m8;
    c->mC = 0;
    c->m4 = 4;
    func_00105260(D_0038C308 + 8, c->m0);
    c->m8 = 0;
    c->m1C = func_0010FC30();
    c->m3BC = 0x7335AB7F;
    func_001E8A50(params, D_00392C38, &c->m378, 1);
    func_001E81F0(params, D_00392D00, &c->m328, 0);
    func_001E7D18(params, D_0037C0C0, &a, 1);
    func_001E7D18(params, D_0037C0B0, &b, 1);
    func_00331A9C(c->mA0, b);
    func_00331A9C(c->m120, a);
    func_001E88F8(params, D_00392CD8, &c->m32C, 0);
    func_001E88F8(params, D_00392C98, &c->m330, 0);
    func_001E88F8(params, D_00392D08, &c->m334, 0);
    func_001E88F8(params, D_0037C060, &c->m338, 0);
    func_001E88F8(params, D_0037C070, &c->m33C, 0);
    func_001E88F8(params, D_0037C080, &c->m340, 0);
    func_001E88F8(params, D_00392CA8, &c->m344, 0);
    func_001E8A50(params, D_0037C090, &c->m348, 0);
    func_001E88F8(params, D_00392CC0, &c->m34C, 0);
    t.m24 = 10;
    t.m18 = func_002D57C8;
    t.m1C = func_002A84B8(m);
    t.m20 = 0x8000;
    t.m10 = 0x152;
    func_00106038(&t);
    func_002A84C0(m, t.m14);
    func_0031BCE0(c->m320);
    func_0031BAC0(func_002A84D0(m), c);
    func_0031BCC0(c->m320);
    return true;
}
