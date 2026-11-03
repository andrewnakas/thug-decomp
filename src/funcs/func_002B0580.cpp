extern char D_00371C78[];

struct Iter_002B0580 {
    int m0;
    int m4;
    void* m8;
    Iter_002B0580() { m4 = 0; m8 = D_00371C78; }
    ~Iter_002B0580() { m8 = D_00371C78; }
};

struct Msg_002B0580 {
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

struct Pkt_002B0580 {
    unsigned char m0;
    int m4;
};

struct Team_002B0580 {
    char pad[0x18];
    int m18;
    int ID() const { return m18; }
};

struct Elem_002B0580 {
    char pad0[0x18];
    Team_002B0580* m18;
};

struct Data_002B0580 {
    unsigned char m0;
    int m4;
};

extern "C" int func_002A7660(void* s);
extern "C" void* func_00240850();
extern "C" void* func_0023BAD8(void* p, int id, int v);
extern "C" Elem_002B0580* func_002A5248(void* s, int id);
extern "C" Msg_002B0580* func_001FA800(Msg_002B0580* m);
extern "C" Elem_002B0580* func_002A53F8(void* self, Iter_002B0580* it, int a);
extern "C" Elem_002B0580* func_002A5490(void* self, Iter_002B0580* it, int a);
extern "C" int func_002B3080(Elem_002B0580* o);
extern "C" void func_001FF970(void* q, int id, Msg_002B0580* m);

struct Obj_002B0580 {
    Data_002B0580* m0;
    char pad4[0xC];
    void* m10;
    int m14;
    int m18;
    void* m1C;
    int Handle();
};

int Obj_002B0580::Handle()
{
    void* mgr = m1C;
    Data_002B0580* d = m0;
    int r = func_002A7660(mgr);
    if (d->m0 != r)
        return 3;
    if (!func_0023BAD8(func_00240850(), d->m4, 1))
        return 1;
    Elem_002B0580* e = func_002A5248(mgr, m14);
    if (e->m18) {
        Iter_002B0580 it;
        Pkt_002B0580 pk;
        Msg_002B0580 msg;
        func_001FA800(&msg);
        pk.m4 = d->m4;
        pk.m0 = e->m18->ID();
        msg.m_data = &pk;
        msg.m_size = 8;
        msg.m_type = 0x6F;
        for (Elem_002B0580* x = func_002A53F8(mgr, &it, 0); x; x = func_002A5490(mgr, &it, 0)) {
            if (e != x)
                func_001FF970(m10, func_002B3080(x), &msg);
        }
    }
    return 1;
}
