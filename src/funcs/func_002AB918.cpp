struct Pkt_002AB918 {
    unsigned char m0;
    char name[0x10];
    unsigned char m11;
    char pad12[2];
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
};

struct Src_002AB918 {
    int m0;
    int m4;
    int m8;
    int mC;
    unsigned char m10;
    signed char m11;
    char pad12[2];
    int m14;
    char name[0x10];
    char m28[4];
};

struct Mgr_002AB918 {
    char pad[0x160];
    int m160;
};

extern char D_00378DB0[];
extern "C" void func_002B3100(Pkt_002AB918* p);
extern "C" void func_002B3168(Pkt_002AB918* p, int f);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" void func_002617C8(int a, char* b);
extern "C" void func_002A44C0(Mgr_002AB918* o, Pkt_002AB918* p, int delay);
extern "C" int func_001F0D78(char* s);
extern "C" void func_002A7B50(Mgr_002AB918* s, int a, int b, char* c, int d, int e, int f, int g, int h);

struct Obj_002AB918 {
    Src_002AB918* m0;
    char pad[0x18];
    Mgr_002AB918* m1C;
    bool Send();
};

bool Obj_002AB918::Send()
{
    Src_002AB918* s = m0;
    Mgr_002AB918* m = m1C;
    Pkt_002AB918 pkt;
    func_002B3100(&pkt);
    func_00331A9C(pkt.name, s->name);
    pkt.m11 = s->m10;
    pkt.m14 = 0;
    int fl = s->m8;
    pkt.m20 = fl;
    pkt.m28 = s->m11;
    pkt.m2C = s->m0;
    pkt.m30 = s->m4;
    pkt.m34 = s->mC;
    pkt.m38 = s->m14;
    if (!(fl & 5)) func_002617C8(pkt.m1C, s->m28);
    if (!m->m160) {
        func_002A44C0(m, &pkt, 0);
    } else {
        func_002A7B50(m, 0, func_001F0D78(D_00378DB0), pkt.name, 0, 0, 0, 0, 0x7D0);
        func_002A44C0(m, &pkt, 10);
    }
    func_002B3168(&pkt, 2);
    return true;
}
