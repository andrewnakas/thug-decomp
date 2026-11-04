extern char D_00371C78[];

struct Iter_002A71E0 {
    int m0;
    int m4;
    void* m8;
    Iter_002A71E0() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A71E0() { m8 = D_00371C78; }
};

struct Msg_002A71E0 {
    unsigned char type;
    char pad1;
    short size;
    void* data;
    char pad8[4];
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

struct Name_002A71E0 {
    char s[32];
};

struct Info_002A71E0 {
    long m0;
    long m8;
    long m10;
    int m18;
    int m1C;
    unsigned char m20;
    unsigned char m21;
    int m24;
    unsigned char m28;
    char pad29[3];
    Name_002A71E0 m2C;
};

struct Elem_002A71E0 {
    char pad[0x24];
    int m24;
    char pad28[0x14C - 0x28];
    unsigned int m14C;
};

struct Obj_002A71E0 {
    char pad[0x10];
    void* m10;
    char pad14[0x24 - 0x14];
    unsigned int m24;
    int m28;
    char pad2C;
    unsigned char m2D;
    char pad2E[0x50 - 0x2E];
    Name_002A71E0 m50;
    unsigned char m70;
    void Start();
};

extern void* D_0038FC78;
extern int D_00390EF8;
extern char D_00392170[];
extern char D_003788E0[];
extern char D_003788F8[];
extern char D_00392178[];
extern char D_003920A0[];
extern char D_003788C0[];
extern char D_00378328[];
extern char D_00378908[];
extern char D_00392180[];

extern "C" void func_001FA800(Msg_002A71E0* m);
extern "C" int func_002A19A8(Obj_002A71E0* o);
extern "C" void* func_002A6070(Obj_002A71E0* o);
extern "C" void* func_0022E058(void* g);
extern "C" void* func_002A39D8(Obj_002A71E0* o);
extern "C" void func_0029F6C8(Obj_002A71E0* o);
extern "C" unsigned int func_002A7668(Obj_002A71E0* o);
extern "C" void func_002A6B98(Obj_002A71E0* o);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" int func_00202FC8(void* p, unsigned int a, unsigned int b);
extern "C" unsigned int func_00203018(void* p, unsigned int a, unsigned int b);
extern "C" int func_002A76F0(Obj_002A71E0* o);
extern "C" int func_002A7750(Obj_002A71E0* o);
extern "C" unsigned char func_002A7080(Obj_002A71E0* o);
extern "C" int func_002A1CE8(Obj_002A71E0* o);
extern "C" int func_00100030(int n);
extern "C" Elem_002A71E0* func_002A53F8(Obj_002A71E0* o, Iter_002A71E0* it, int a);
extern "C" Elem_002A71E0* func_002A5490(Obj_002A71E0* o, Iter_002A71E0* it, int a);
extern "C" void func_002B2310(Elem_002A71E0* e);
extern "C" int func_002B3080(Elem_002A71E0* e);
extern "C" void func_001FF970(void* q, int id, Msg_002A71E0* m);
extern "C" Elem_002A71E0* func_002A5820(Obj_002A71E0* o);
extern "C" void func_002B2BC0(void* p, int v);
extern "C" void func_002A7EA8(Obj_002A71E0* o, int v);
extern "C" void func_002A7EB8(Obj_002A71E0* o, int v);
extern "C" void func_002A8020(Obj_002A71E0* o);
extern "C" void func_002A7598(Obj_002A71E0* o);
extern "C" int func_002D9340(void* p);
extern "C" void func_002D9B18(void* p);

void Obj_002A71E0::Start()
{
    Iter_002A71E0 it;
    Msg_002A71E0 msg;
    Info_002A71E0 info;
    void* g = D_0038FC78;
    func_001FA800(&msg);
    void* net;
    if (func_002A19A8(this))
        net = func_002A6070(this);
    else
        net = func_0022E058(g);
    void* q = func_002A39D8(this);
    func_0029F6C8(this);
    m24 = func_002A7668(this);
    func_002A6B98(this);
    int room;
    if (m24 == func_001F0D78(D_00392170))
        room = func_00202FC8(net, func_001F0D78(D_003788E0), func_001F0D78(D_00392178));
    else
        room = func_00202FC8(net, func_001F0D78(D_003788F8), func_001F0D78(D_00392178));
    m28 = func_002A76F0(this);
    info.m0 = m24;
    info.m18 = func_002A7750(this);
    if (m24 == 0xEC200EAA || m24 == 0x5D32129C || m24 == 0x6EF8FDA0 || m24 == 0x1498240A
        || m24 == 0xF135ECB6 || m24 == 0x3D6D444F || m24 == 0xBFF33600)
        info.m8 = 0;
    else if (m24 != func_001F0D78(D_003920A0))
        info.m8 = room;
    else if (func_00203018(net, func_001F0D78(D_003788C0), func_001F0D78(D_00378328)) != 0x938AB24B)
        info.m8 = 0;
    else
        info.m8 = room;
    info.m20 = func_002A7080(this);
    info.m10 = func_00202FC8(net, func_001F0D78(D_00378908), func_001F0D78(D_00392180));
    info.m24 = func_002A1CE8(this);
    do {
        info.m21 = func_00100030(0xFF) + 1;
    } while (info.m21 == m2D);
    info.m28 = m70;
    info.m2C = m50;
    msg.data = &info;
    msg.size = 0x50;
    msg.type = 0x34;
    msg.mC = 2;
    msg.m10 = 8;
    Elem_002A71E0* e = func_002A53F8(this, &it, 1);
    while (e) {
        e->m24 = 0;
        func_002B2310(e);
        e->m14C &= ~0x8000;
        func_001FF970(q, func_002B3080(e), &msg);
        if (!func_002A19A8(this)) break;
        e = func_002A5490(this, &it, 1);
    }
    e = func_002A5820(this);
    if (e) func_002B2BC0(e, 0);
    func_002A7EA8(this, 0);
    func_002A7EB8(this, -1);
    func_002A8020(this);
    func_002A7598(this);
    D_00390EF8 = 0;
    if (func_002D9340(m10)) func_002D9B18(m10);
}
