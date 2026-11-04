extern char D_00371C78[];

struct Iter_002A7B50 {
    int m0;
    int m4;
    void* m8;
    Iter_002A7B50() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A7B50() { m8 = D_00371C78; }
};

struct Msg_002A7B50 {
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

struct Data_002A7B50 {
    int m_crc;
    int m_id;
    int m_v;
    char m_a[16];
    char m_b[16];
};

extern char D_00392188[];
extern char D_00392190[];
extern char D_00392090[];
extern char D_00378950[];
extern char D_00378960[];
extern char D_00378970[];

extern "C" Msg_002A7B50* func_001FA800(Msg_002A7B50* m);
extern "C" int func_001F0D78(char* s);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" char* func_00331678(char* d, const char* s);
extern "C" char* func_003364D8(char* s, char* p);
extern "C" int func_002B3080(void* o);
extern "C" void func_001FF970(void* q, int id, Msg_002A7B50* m);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" char* func_001E54E8(int id, int v);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001E7A68(void* s, int name, int type, int v);
extern "C" void func_001E7200(void* p, int key, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

struct Table_002A7B50 {
    char pad0[0x14];
    void* m14;
    void Send(int net, int id, char* a, char* b, int unused, char* name, int reliable, int v);
};

extern "C" void* func_002A53F8(Table_002A7B50* self, Iter_002A7B50* it, int a);
extern "C" void* func_002A5490(Table_002A7B50* self, Iter_002A7B50* it, int a);

void Table_002A7B50::Send(int net, int id, char* a, char* b, int unused, char* name, int reliable, int v)
{
    if (net) {
        Iter_002A7B50 it;
        Data_002A7B50 d;
        Msg_002A7B50 msg;
        func_001FA800(&msg);
        d.m_id = id;
        d.m_v = v;
        d.m_a[0] = 0;
        d.m_b[0] = 0;
        d.m_crc = func_001F0D78(name);
        if (a) func_00331A9C(d.m_a, a);
        if (b) func_00331A9C(d.m_b, b);
        msg.m_data = &d;
        msg.m_size = sizeof(d);
        msg.m_type = 0x3F;
        if (reliable) {
            msg.m_C = 2;
            msg.m_10 = 8;
        }
        for (void* e = func_002A53F8(this, &it, 1); e; e = func_002A5490(this, &it, 1)) {
            func_001FF970(m14, func_002B3080(e), &msg);
        }
    } else {
        void* p = func_001E6978(func_001190D0(8));
        char* s = func_001E54E8(id, 0);
        char buf[256];
        func_00331A9C(buf, s);
        char* c = func_003364D8(buf, D_00392188);
        if (c) {
            char buf2[256];
            *c = 0;
            func_00331A9C(buf2, buf);
            func_00331678(buf2, a);
            func_00331678(buf2, c + 3);
            func_001E7A30(p, func_001F0D78(D_00392190), 3, buf2);
        } else {
            func_001E7A30(p, func_001F0D78(D_00392190), 3, s);
        }
        func_001E7A68(p, func_001F0D78(D_00392090), 0xD, func_001F0D78(D_00378950));
        func_001E7200(p, func_001F0D78(D_00378960), v);
        func_001F0370(D_00378970, p, 0, 0);
        if (p) func_001E6AE8(p, 3);
    }
}
