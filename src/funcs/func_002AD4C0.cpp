extern char D_00371C78[];

struct Iter_002AD4C0 {
    int m0;
    int m4;
    void* m8;
    Iter_002AD4C0() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002AD4C0() { m8 = D_00371C78; }
};

struct Msg_002AD4C0 {
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

struct Data_002AD4C0 {
    unsigned char m0;
    unsigned char m1;
};

struct Player_002AD4C0 {
    char pad0[0x18];
    int m18;
    int ID() const { return m18; }
};

struct Elem_002AD4C0 {
    char pad0[0x18];
    Player_002AD4C0* m18;
    char pad1C[0x30 - 0x1C];
    int m30;
    char pad34[0x14C - 0x34];
    unsigned int m14C;
};

struct Table_002AD4C0 {
    char pad0[0x70];
    int m70;
};

extern void* D_0038FC78;
extern char D_00392290[];
extern char D_00378FB0[];
extern char D_00392298[];
extern char D_003922A0[];
extern char D_00378FC0[];
extern char D_00378FD0[];
extern char D_00378FF0[];
extern char D_003922A8[];
extern char D_003922B0[];

extern "C" Elem_002AD4C0* func_002A5248(Table_002AD4C0* s, int id);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_001F0D78(char* s);
extern "C" int func_002B22B8(Elem_002AD4C0* e);
extern "C" int func_002B22C8(Elem_002AD4C0* e);
extern "C" Msg_002AD4C0* func_001FA800(Msg_002AD4C0* m);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" int func_001E54B8(char* s, int v);
extern "C" void func_001E7A30(void* p, int name, int type, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" int func_002B1FC8(Elem_002AD4C0* e);
extern "C" int func_002B1FE8(Elem_002AD4C0* e);
extern "C" Elem_002AD4C0* func_002A56E0(Table_002AD4C0* t);
extern "C" void func_002B2310(Elem_002AD4C0* e);
extern "C" Elem_002AD4C0* func_002A53F8(Table_002AD4C0* self, Iter_002AD4C0* it, int a);
extern "C" Elem_002AD4C0* func_002A5490(Table_002AD4C0* self, Iter_002AD4C0* it, int a);
extern "C" int func_002B3080(Elem_002AD4C0* o);
extern "C" void func_001FF970(void* q, int id, Msg_002AD4C0* m);
extern "C" int func_002B2F30(Elem_002AD4C0* e);
extern "C" void func_002B2BC0(Elem_002AD4C0* e, int v);
extern "C" int func_00100030(int n);

struct Obj_002AD4C0 {
    int m0;
    char pad4[0xC];
    void* m10;
    int m14;
    int m18;
    Table_002AD4C0* m1C;
    bool Handle();
};

bool Obj_002AD4C0::Handle()
{
    Table_002AD4C0* t = m1C;
    void* sk = D_0038FC78;
    Elem_002AD4C0* e = func_002A5248(t, m14);
    if (e) e->m14C &= ~0x8000;
    if (func_0024F938(func_0022E358(sk)) == func_001F0D78(D_00392290)) {
        if (e && func_002B22B8(e)) {
        Iter_002AD4C0 it;
        char buf[64];
        Data_002AD4C0 d;
        Msg_002AD4C0 msg;
        func_001FA800(&msg);
        int id = func_002B22C8(e);
        func_003331D0(buf, D_00378FB0, id + 1);
        void* p = func_001E6978(func_001190D0(8));
        func_001E7268(p, D_00392298, id);
        func_001E7A30(p, func_001F0D78(D_003922A0), 3, func_001E54B8(buf, 0));
        func_001F0370(D_00378FC0, p, 0, 0);
        if (p) func_001E6AE8(p, 3);
        d.m1 = id;
        d.m0 = e->m18->ID();
        if (func_002B1FC8(e)) func_001F0370(D_00378FD0, 0, 0, 0);
        Elem_002AD4C0* o = func_002A56E0(t);
        if (o && !func_002B1FE8(o) && o->m30 == id) func_001F0370(D_00378FF0, 0, 0, 0);
        func_002B2310(e);
        msg.m_data = &d;
        msg.m_size = 2;
        msg.m_type = 0x75;
        msg.m_C = 2;
        msg.m_10 = 8;
        for (Elem_002AD4C0* x = func_002A53F8(t, &it, 1); x; x = func_002A5490(t, &it, 1)) {
            if (!func_002B1FC8(x)) func_001FF970(m10, func_002B3080(x), &msg);
        }
        }
    } else if (func_0024F938(func_0022E358(sk)) == func_001F0D78(D_003922A8) ||
               func_0024F938(func_0022E358(sk)) == func_001F0D78(D_003922B0)) {
        if (e && func_002B2F30(e)) {
        Iter_002AD4C0 it;
        Msg_002AD4C0 msg;
        func_001FA800(&msg);
        func_002B2BC0(e, 0);
        t->m70 = func_00100030(10);
        signed char c;
        c = t->m70;
        msg.m_data = &c;
        msg.m_size = 1;
        msg.m_type = 0x58;
        msg.m_C = 2;
        msg.m_10 = 8;
        for (e = func_002A53F8(t, &it, 1); e; e = func_002A5490(t, &it, 1)) {
            func_001FF970(m10, func_002B3080(e), &msg);
        }
        }
    }
    return true;
}
