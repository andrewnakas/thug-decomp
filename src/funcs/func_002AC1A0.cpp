extern char D_00371C78[];
extern char D_003714C0[];

struct IterA_002AC1A0 {
    int m0;
    int m4;
    void* m8;
    IterA_002AC1A0() { m8 = D_00371C78; m4 = 0; }
    ~IterA_002AC1A0() { m8 = D_00371C78; }
};

struct IterB_002AC1A0 {
    int m0;
    int m4;
    void* m8;
    IterB_002AC1A0() { m8 = D_003714C0; m4 = 0; }
    ~IterB_002AC1A0() { m8 = D_003714C0; }
};

struct Info_002AC1A0 {
    signed char b0;
    signed char b1;
    signed char b2;
    signed char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    char name[0x10];
    char s18[0x20];
    char s38[0x20];
    unsigned char m58;
    int m5C;
    char names[8][0x10];
};

struct Item_002AC1A0 {
    char pad0[0x34];
    char name[0x10];
};

struct Elem_002AC1A0 {
    char m0;
    char name[0x1F];
    int m20;
};

struct Conn_002AC1A0 {
    char pad[0x4C];
    int m4C;
    unsigned short m50;
};

struct Mgr_002AC1A0 {
    char pad[0xC];
    void* mC;
};

extern char D_00378E18[];
extern char D_00378E28[];
extern char D_00378DC8[];
extern char D_00392278[];
extern char D_00392280[];
extern void* D_0038FC78;
extern "C" int func_002A1A28(Mgr_002AC1A0* m);
extern "C" void* func_002A6070(Mgr_002AC1A0* m);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" bool func_001E8890(void* p, char* name, char** out, int v);
extern "C" char* func_00332088(char* dst, const char* src, int n);
extern "C" void* func_002A39D8(Mgr_002AC1A0* m);
extern "C" int func_002A1A48(Mgr_002AC1A0* m);
extern "C" int func_002A39F8(Mgr_002AC1A0* m);
extern "C" int func_002A1B30(Mgr_002AC1A0* m);
extern "C" int func_002A3B50(Mgr_002AC1A0* m);
extern "C" int func_002A1FF0(Mgr_002AC1A0* m);
extern "C" char* func_002A2270(Mgr_002AC1A0* m);
extern "C" int func_00331950(char* a, char* b);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_002A1968(Mgr_002AC1A0* m);
extern "C" int func_002D7EB8(void* p);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" char* func_002A22D0(Mgr_002AC1A0* m, int v);
extern "C" char* func_002A23F0(Mgr_002AC1A0* m);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" Item_002AC1A0* func_002A53F8(Mgr_002AC1A0* m, IterA_002AC1A0* it, int a);
extern "C" Item_002AC1A0* func_002A5490(Mgr_002AC1A0* m, IterA_002AC1A0* it, int a);
extern "C" int func_002B1FE8(Item_002AC1A0* e);
extern "C" int func_002B30F0(Item_002AC1A0* e);
extern "C" Elem_002AC1A0* func_002A5520(Mgr_002AC1A0* m, IterB_002AC1A0* it);
extern "C" Elem_002AC1A0* func_002A5558(Mgr_002AC1A0* m, IterB_002AC1A0* it);
extern "C" int func_00200C68(void* obj, int type, int size, void* data, int a, int b, int c);

struct Obj_002AC1A0 {
    int* m0;
    char pad4[4];
    long m8;
    char pad10[4];
    Conn_002AC1A0* m14;
    char pad18[4];
    Mgr_002AC1A0* m1C;
    int Handle();
};

int Obj_002AC1A0::Handle()
{
    IterA_002AC1A0 ita;
    IterB_002AC1A0 itb;
    Info_002AC1A0 info;
    char buf[0x10];
    char* str;
    void* g = D_0038FC78;
    if (m8 != 4) return 3;
    Mgr_002AC1A0* m = m1C;
    if (func_002A1A28(m)) return 3;
    func_001E8890(func_00202EF8(func_002A6070(m), func_001F0D78(D_00378E18)), D_00378E28, &str, 1);
    int* p = m0;
    func_00332088(buf, str, 0xF);
    buf[0xF] = 0;
    void* q = func_002A39D8(m);
    info.m58 = func_002A1A48(m);
    info.b0 = func_002A39F8(m);
    info.b1 = func_002A1B30(m);
    info.b2 = func_002A3B50(m);
    info.b3 = func_002A1FF0(m);
    if (info.b1 < info.b0) info.b1 = info.b0;
    if (info.b3 < info.b2) info.b3 = info.b2;
    if (func_00331950(func_002A2270(m), D_00392278) == 0) {
        info.b4 = 0;
    } else {
        info.b4 = 1;
    }
    if (func_0024F938(func_0022E358(g)) == func_001F0D78(D_00378DC8)) {
        info.b5 = 0;
    } else {
        info.b5 = 1;
    }
    info.b6 = func_002A1968(m);
    info.b7 = 0;
    if (func_002A1A28(m)) {
        if (func_002D7EB8(m->mC)) info.b7 = 1;
    }
    func_00331A9C(info.name, buf);
    int n = 0;
    func_003331D0(info.s18, D_00392280, func_002A22D0(m, 1));
    func_003331D0(info.s38, D_00392280, func_002A23F0(m));
    info.m5C = *p;
    for (Item_002AC1A0* e = func_002A53F8(m, &ita, 1); e; e = func_002A5490(m, &ita, 1)) {
        if (!func_002B1FE8(e) || func_002B30F0(e)) {
            func_003331D0(info.names[n], e->name);
            n++;
        }
    }
    for (Elem_002AC1A0* x = func_002A5520(m, &itb); x; x = func_002A5558(m, &itb)) {
        if ((x->m20 & 0x1C) != 4) {
            func_003331D0(info.names[n], x->name);
            n++;
        }
    }
    func_00200C68(q, 0x10, sizeof(info), &info, m14->m4C, m14->m50, 0);
    return 1;
}
