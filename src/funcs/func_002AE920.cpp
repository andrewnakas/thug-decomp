struct Msg_002AE920 {
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

struct Data_002AE920 {
    int m0;
    char m4;
};

struct P_002AE920 {
    char pad[0x48];
    int m48;
};

struct Hdr_002AE920 {
    int m0;
    signed char m4;
};

extern char D_003792F0[];
extern char D_00379300[];
extern char D_00378DE8[];
extern "C" void* func_002A5248(void* s, P_002AE920* id);
extern "C" void* func_002C0368();
extern "C" int func_002BCE20(void* p, int v);
extern "C" void* func_0029C320();
extern "C" int func_0029A2C8(void* p);
extern "C" int func_002AB438(void* s);
extern "C" void func_002AB468(void* s, int v);
extern "C" int func_002AB4C8(void* s);
extern "C" int func_002AB4C0(void* s);
extern "C" void func_00200998(void* q, int a, int type, int id, int v, char* name, int b, int c, int d);
extern "C" Msg_002AE920* func_001FA800(Msg_002AE920* m);
extern "C" unsigned int func_0010FC30();
extern "C" int func_002B3080(void* o);
extern "C" void func_001FF970(void* q, int id, Msg_002AE920* m);
extern "C" void func_002B2F40(void* o, unsigned int t);
extern "C" void func_002010D0(void* w, int a);

struct Obj_002AE920 {
    Hdr_002AE920* m0;
    char pad4[0xC];
    void* m10;
    P_002AE920* m14;
    int m18;
    void* m1C;
    bool Handle();
};

bool Obj_002AE920::Handle()
{
    void* s = m1C;
    void* it = func_002A5248(s, m14);
    void* q = m10;
    Hdr_002AE920* h = m0;
    int a = m14->m48;
    func_00200998(q, a, 0x6C, 0x3A98, func_002BCE20(func_002C0368(), 0), D_003792F0, 8, 0, 1);
    a = m14->m48;
    func_0029C320();
    func_00200998(q, a, 0x88, 0x1132, func_0029A2C8(func_0029C320()), D_00379300, 8, 0, 1);
    if (func_002AB438(s)) {
        func_002AB468(s, h->m0);
        int b = m14->m48;
        unsigned short id = func_002AB4C8(s);
        func_00200998(q, b, 0x87, id, func_002AB4C0(s), D_00378DE8, 8, 0, 1);
    }
    signed char t = h->m4;
    if (t == 0x46) {
        Data_002AE920 d;
        Msg_002AE920 msg;
        func_001FA800(&msg);
        d.m0 = h->m0;
        d.m4 = 0;
        unsigned int now = func_0010FC30();
        msg.m_data = &d;
        msg.m_C = 2;
        msg.m_size = 8;
        msg.m_10 = 8;
        msg.m_type = t;
        func_001FF970(q, func_002B3080(it), &msg);
        msg.m_data = &now;
        msg.m_size = 4;
        msg.m_type = 0x25;
        func_001FF970(q, func_002B3080(it), &msg);
        func_002B2F40(it, now);
        func_002010D0(q, 0);
    }
    return true;
}
