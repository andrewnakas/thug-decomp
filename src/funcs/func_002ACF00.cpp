extern char D_00366B58[];

struct Iter_002ACF00 {
    int m0;
    int m4;
    void* m8;
    Iter_002ACF00() { m8 = D_00366B58; m4 = 0; }
    ~Iter_002ACF00() { m8 = D_00366B58; }
};

struct Msg_002ACF00 {
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

struct Pkt_002ACF00 {
    unsigned int m0;
    unsigned char m4;
    unsigned char m5;
    unsigned char m6;
    int m8;
    int mC;
    int m10;
    int m14;
    unsigned char m18;
    char pad19[7];
    char name[0x10];
    char data[0x1000];
};

struct Data_002ACF00 {
    int m0;
    int m4;
    int m8;
    char mC[0x10];
    signed char m1C;
    signed char m1D;
};

struct Mgr_002ACF00 {
    char pad0[4];
    void* m4;
    char pad8[4];
    void* mC;
    void* m10;
    char pad14[0x174 - 0x14];
    int m174;
    int m178;
};

extern void* D_0038EB78;
extern void* D_0038FC78;
extern char D_00378F58[];
extern char D_00378F70[];
extern char D_00378F88[];
extern char D_00378FA0[];
extern char D_00378E28[];

extern "C" Msg_002ACF00* func_001FA800(Msg_002ACF00* m);
extern "C" int func_00202778(void* c);
extern "C" void func_00202B38(void* c, int v);
extern "C" void func_002A39D0(Mgr_002ACF00* s, int port);
extern "C" int func_002D7EB8(void* p);
extern "C" void func_002D30B0(void* p, char* q);
extern "C" int func_002A39B8(Mgr_002ACF00* m);
extern "C" int func_002D30D0(void* p);
extern "C" int func_002D30A8(void* p);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_002A18E0(Mgr_002ACF00* m);
extern "C" int func_001E54B8(char* s, int v);
extern "C" void func_002D8248(void* p, int a, int b, char* c);
extern "C" void* func_0022E358(void* p);
extern "C" void func_0024F728(void* p, int v);
extern "C" void* func_002A6070(Mgr_002ACF00* m);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" bool func_001E8890(void* p, char* name, char** out, int v);
extern "C" int func_002D8158(void* p);
extern "C" void* func_002DA188(void* p);
extern "C" int func_002DA2A8(void* p);
extern "C" int func_001FA648(void* g);
extern "C" char* func_00331A9C(char* d, char* s);
extern "C" void* func_0022E3C8(void* p, int v);
extern "C" void* func_00200EC0(void* p, Iter_002ACF00* it);
extern "C" int func_00202B30(void* p);
extern "C" int func_002616E0(void* p, char* buf, int size, int v);
extern "C" void func_00200C00(void* q, Msg_002ACF00* m);
extern "C" void func_002A8250(Mgr_002ACF00* s, int v);

struct Obj_002ACF00 {
    Data_002ACF00* m0;
    char pad4[0xC];
    void* m10;
    void* m14;
    char pad18[4];
    Mgr_002ACF00* m1C;
    int Handle();
};

int Obj_002ACF00::Handle()
{
    Pkt_002ACF00 pkt;
    Msg_002ACF00 msg;
    char* str;
    void* net = D_0038EB78;
    func_001FA800(&msg);
    void* sk = D_0038FC78;
    Mgr_002ACF00* mgr = m1C;
    Data_002ACF00* d = m0;
    if (func_00202778(m14)) {
        if (d->m1D)
            func_00202B38(m14, 0);
        else
            func_00202B38(m14, 1);
        mgr->m174 = d->m0;
        mgr->m178 = d->m4;
        func_002A39D0(mgr, d->m8);
        if (func_002D7EB8(mgr->mC)) {
            char buf[0x400];
            func_002D30B0(mgr->m4, d->mC);
            char* fmt = D_00378F58;
            char* p = buf;
            int a = func_002A39B8(mgr);
            int b = func_002D30D0(mgr->m4);
            int c = func_002D30A8(mgr->m4);
            func_003331D0(p, fmt, mgr->m174, mgr->m178, a, b, c);
            if (!func_002A18E0(mgr))
                func_002D8248(mgr->mC, 2, func_001E54B8(D_00378F70, 0), p);
            else
                func_002D8248(mgr->mC, 2, func_001E54B8(D_00378F88, 0), p);
        }
    }
    func_0024F728(func_0022E358(sk), d->m1C);
    func_001E8890(func_00202EF8(func_002A6070(mgr), func_001F0D78(D_00378FA0)), D_00378E28, &str, 1);
    pkt.m10 = func_002D8158(mgr->mC);
    pkt.m14 = func_002DA2A8(func_002DA188(mgr->m10));
    int h = func_002A18E0(mgr);
    pkt.m0 = 0x30036;
    pkt.m4 = h == 1;
    pkt.m5 = 1;
    int other;
    if (func_001FA648(net) == 1) {
        other = 1;
        pkt.m18 = 0;
    } else {
        other = 0;
        pkt.m18 = 1;
    }
    func_00331A9C(pkt.name, str);
    pkt.m6 = 0;
    int len = 0;
    if (!pkt.m4) {
        void* q = func_0022E3C8(D_0038FC78, 0);
        Iter_002ACF00 it;
        int v = func_00202B30(func_00200EC0(m10, &it)) == 1 ? 1 : other;
        len = func_002616E0(q, pkt.data, 0x1000, v);
    }
    msg.m_size = len + 0x30;
    msg.m_type = 0x50;
    msg.m_data = &pkt;
    if (func_00202778(m14))
        msg.m_C = 1;
    func_00200C00(m10, &msg);
    func_002A8250(mgr, 2);
    return 3;
}
