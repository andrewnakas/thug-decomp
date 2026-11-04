extern char D_00371C78[];

struct Iter_002A5A88 {
    int m0;
    int m4;
    void* m8;
    Iter_002A5A88() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A5A88() { m8 = D_00371C78; }
};

struct Msg_002A5A88 {
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

struct Data_002A5A88 {
    unsigned char m0;
    unsigned char m1;
};

struct Player_002A5A88 {
    char pad0[0x18];
    int m18;
    int ID() const { return m18; }
};

struct Conn_002A5A88 {
    char pad0[0x4C];
    int m4C;
    unsigned short m50;
};

struct Elem_002A5A88 {
    char pad0[0x18];
    Player_002A5A88* m18;
    Conn_002A5A88* m1C;
    char pad20[0x30 - 0x20];
    int m30;
    char m34[0x14C - 0x34];
    unsigned char m14C;
    unsigned char m14D;
    bool Ready() const { return m14D & 1; }
};

extern void* D_0038FC78;
extern char D_003784D8[];
extern char D_003784F0[];
extern char D_00378508[];
extern char D_00378528[];
extern char D_00378550[];
extern char D_00378570[];
extern char D_00378590[];
extern char D_003785B0[];
extern char D_00378480[];
extern char D_00392130[];
extern char D_00392138[];
extern char D_00378490[];
extern char D_003784A0[];
extern char D_00377D78[];
extern char D_003785D0[];

struct Table_002A5A88;
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_002B1FE8(Elem_002A5A88* e);
extern "C" int func_002B1FC8(Elem_002A5A88* e);
extern "C" void* func_0022E358(void* p);
extern "C" void* func_0022E048(void* p);
extern "C" int func_0024F8D8(void* p, char* s);
extern "C" int func_0024F938(void* p);
extern "C" void func_002656D8(void* p, int id);
extern "C" int func_002A1A38(Table_002A5A88* t);
extern "C" void func_002A47D8(Table_002A5A88* t, Elem_002A5A88* e);
extern "C" Elem_002A5A88* func_002A53F8(Table_002A5A88* self, Iter_002A5A88* it, int a);
extern "C" Elem_002A5A88* func_002A5490(Table_002A5A88* self, Iter_002A5A88* it, int a);
extern "C" Msg_002A5A88* func_001FA800(Msg_002A5A88* m);
extern "C" int func_002B3080(Elem_002A5A88* o);
extern "C" void func_001FF970(void* q, int id, Msg_002A5A88* m);
extern "C" int func_002D9340(void* p);
extern "C" void func_002DA0C0(void* p, int id);
extern "C" int func_00200C68(void* q, int type, int size, void* data, int a, int b, int c);
extern "C" void func_002012C0(void* q, Conn_002A5A88* c);
extern "C" void func_00202710(Conn_002A5A88* c);
extern "C" void func_00201D98(Conn_002A5A88* c);
extern "C" int func_001F0D78(char* s);
extern "C" void func_002A7B50(Table_002A5A88* t, int net, int id, char* a, char* b, int unused, char* name, int reliable, int v);
extern "C" int func_002B2F30(Elem_002A5A88* e);
extern "C" void func_00268100(void* p);
extern "C" void func_002B2BC0(Elem_002A5A88* e, int v);
extern "C" int func_002B22B8(Elem_002A5A88* e);
extern "C" int func_002B22C8(Elem_002A5A88* e);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" int func_001E54B8(char* s, int v);
extern "C" void func_001E7A30(void* p, int name, int type, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" Elem_002A5A88* func_002A56E0(Table_002A5A88* t);
extern "C" void func_002B2310(Elem_002A5A88* e);
extern "C" int func_002B1FD8(Elem_002A5A88* e);
extern "C" void func_002A4C78(Table_002A5A88* t);
extern "C" int func_002A5780(Table_002A5A88* t);

struct Table_002A5A88 {
    char pad0[0x10];
    void* m10;
    void* m14;
    char pad18[0x74 - 0x18];
    void* m74;
    void Remove(Elem_002A5A88* e, unsigned int why);
};

void Table_002A5A88::Remove(Elem_002A5A88* e, unsigned int why)
{
    char name[16];
    Iter_002A5A88 it;
    void* sk = D_0038FC78;
    func_00331A9C(name, e->m34);
    if (!func_002B1FE8(e) && func_0024F8D8(func_0022E358(sk), D_003784D8))
        func_002656D8(func_0022E048(sk), e->m18->m18);
    if (func_002A1A38(this)) {
    Elem_002A5A88* x;
    if (!func_002B1FE8(e)) {
        for (x = func_002A53F8(this, &it, 1); x; x = func_002A5490(this, &it, 1)) {
            if (func_002B1FC8(x)) continue;
            Data_002A5A88 d;
            Msg_002A5A88 msg;
            func_001FA800(&msg);
            d.m0 = e->m18->ID();
            d.m1 = why;
            msg.m_data = &d;
            msg.m_size = 2;
            msg.m_type = 0x2D;
            msg.m_C = 2;
            msg.m_10 = 8;
            func_001FF970(m14, func_002B3080(x), &msg);
        }
        if (why < 2 || why == 5) {
            if (func_002D9340(m10)) func_002DA0C0(m10, e->m18->m18);
        }
    }
    if (why - 3 < 2) {
        func_00200C68(m14, 0x51, 0, 0, e->m1C->m4C, e->m1C->m50, 0);
        if (why == 3) func_002012C0(m14, e->m1C);
    } else if (why == 6) {
        func_00200C68(m14, 0x56, 0, 0, e->m1C->m4C, e->m1C->m50, 0);
    }
    if (why != 2 && e->m1C) {
        func_00202710(e->m1C);
        func_00201D98(e->m1C);
    }
    int id;
    switch (why) {
    case 0:
        id = func_001F0D78(D_003784F0);
        break;
    case 2:
        id = func_001F0D78(D_00378528);
        break;
    case 3:
        id = func_001F0D78(D_00378550);
        break;
    case 4:
        id = func_001F0D78(D_00378570);
        break;
    case 6:
        id = func_001F0D78(D_00378590);
        break;
    case 5:
        id = func_001F0D78(D_003785B0);
        break;
    case 1:
    default:
        id = func_001F0D78(D_00378508);
        break;
    }
    if (!func_002B1FC8(e)) func_002A7B50(this, 1, id, name, 0, 0, 0, 0, 2000);
    if (why == 2) {
        if (func_002B2F30(e)) {
            if (m74) func_00268100(m74);
            func_002B2BC0(e, 0);
        }
        if (func_002B22B8(e)) {
            int n = func_002B22C8(e);
            char buf[64];
            func_003331D0(buf, D_00378480, n + 1);
            void* p = func_001E6978(func_001190D0(8));
            func_001E7268(p, D_00392130, n);
            func_001E7A30(p, func_001F0D78(D_00392138), 3, func_001E54B8(buf, 0));
            func_001F0370(D_00378490, p, 0, 0);
            if (p) func_001E6AE8(p, 3);
            Elem_002A5A88* o = func_002A56E0(this);
            if (o && !func_002B1FE8(o) && o->m30 == n) func_001F0370(D_003784A0, 0, 0, 0);
            func_002B2310(e);
        }
    } else {
        int r = func_002B1FD8(e);
        func_002A47D8(this, e);
        if (r) {
            func_002A4C78(this);
            if (!func_002A5780(this)) {
                if (func_0024F938(func_0022E358(sk)) != func_001F0D78(D_00377D78))
                    func_001F0370(D_003785D0, 0, 0, 0);
            }
        }
    }
    int all = 1;
    for (x = func_002A53F8(this, &it, 0); x; x = func_002A5490(this, &it, 0)) {
        bool nr = !x->Ready();
        if (nr) {
            all = 0;
            break;
        }
    }
    if (all) {
        Msg_002A5A88 msg;
        func_001FA800(&msg);
        msg.m_type = 0x5A;
        msg.m_C = 2;
        msg.m_10 = 8;
        for (x = func_002A53F8(this, &it, 1); x; x = func_002A5490(this, &it, 1)) {
            func_001FF970(m14, func_002B3080(x), &msg);
        }
    }
    } else {
        func_002A47D8(this, e);
    }
}
