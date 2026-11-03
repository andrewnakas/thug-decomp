extern char D_00371C78[];

struct Iter_002AFF30 {
    int m0;
    int m4;
    void* m8;
    Iter_002AFF30() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002AFF30() { m8 = D_00371C78; }
};

struct Msg_002AFF30 {
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

struct Data_002AFF30 {
    unsigned char m0;
    int m4;
};

struct Mod_002AFF30 {
    int m0[5];
    virtual int V00(int v);
    virtual int V01(int v);
    virtual int V02(int v);
    virtual int V03(int v);
    virtual int V04(int v);
    virtual int V05(int v);
    virtual int V06(int v);
    virtual int V07(int v);
    virtual int V08(int v);
    virtual int V09(int v);
    virtual int V10(int v);
    virtual int V11(int v);
    virtual int V12(int v);
    virtual int V13(int v);
    virtual int V14(int v);
    virtual int V15(int v);
    virtual int V16(int v);
    virtual int V17(int v);
    virtual int V18(int v);
    virtual int V19(int v);
    virtual int V20(int v);
    virtual int V21(int v);
    virtual int V22(int v);
    virtual int V23(int v);
    virtual void V24(int v);
};

struct Player_002AFF30 {
    char pad0[0x18];
    int m18;
    int ID() const { return m18; }
};

struct Elem_002AFF30 {
    char pad0[0x18];
    Player_002AFF30* m18;
    char pad1C[0x30 - 0x1C];
    int m30;
};

struct Hdr_002AFF30 {
    unsigned char m0;
    char pad1[3];
    int m4;
};

extern void* D_0038FC78;
extern "C" unsigned char func_002A7660(void* t);
extern "C" void* func_00240850();
extern "C" Mod_002AFF30* func_0023BAD8(void* p, int id, int v);
extern "C" Elem_002AFF30* func_002A5248(void* s, int id);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F540(void* p);
extern "C" Elem_002AFF30* func_002A53F8(void* self, Iter_002AFF30* it, int a);
extern "C" Elem_002AFF30* func_002A5490(void* self, Iter_002AFF30* it, int a);
extern "C" Msg_002AFF30* func_001FA800(Msg_002AFF30* m);
extern "C" int func_002B3080(void* o);
extern "C" void func_001FF970(void* q, int id, Msg_002AFF30* m);

struct Obj_002AFF30 {
    Hdr_002AFF30* m0;
    char pad4[0xC];
    void* m10;
    int m14;
    int m18;
    void* m1C;
    int Handle();
};

int Obj_002AFF30::Handle()
{
    void* t = m1C;
    Hdr_002AFF30* h = m0;
    if (h->m0 != func_002A7660(t)) return 3;
    Mod_002AFF30* o = func_0023BAD8(func_00240850(), h->m4, 1);
    if (!o) return 1;
    int found = 0;
    Elem_002AFF30* e;
    Elem_002AFF30* me = func_002A5248(t, m14);
    if (!me->m18) return 1;
    if (func_0024F540(func_0022E358(D_0038FC78))) {
        Iter_002AFF30 it;
        for (e = func_002A53F8(t, &it, 0); e; e = func_002A5490(t, &it, 0)) {
            if (me->m30 == e->m30 && o->V18(e->m18->m18)) {
                found = 1;
                break;
            }
        }
        if (!found) {
            o->V24(me->m18->m18);
            for (e = func_002A53F8(t, &it, 0); e; e = func_002A5490(t, &it, 0)) {
                Data_002AFF30 d;
                Msg_002AFF30 msg;
                func_001FA800(&msg);
                d.m4 = h->m4;
                d.m0 = me->m18->ID();
                msg.m_data = &d;
                msg.m_size = 8;
                msg.m_type = 0x6E;
                msg.m_C = 2;
                msg.m_10 = 8;
                func_001FF970(m10, func_002B3080(e), &msg);
            }
        }
    } else {
        if (o->V18(me->m18->m18)) return 1;
        Iter_002AFF30 it;
        Data_002AFF30 d;
        Msg_002AFF30 msg;
        func_001FA800(&msg);
        o->V24(me->m18->m18);
        d.m4 = h->m4;
        d.m0 = me->m18->ID();
        msg.m_data = &d;
        msg.m_type = 0x6E;
        msg.m_C = 2;
        msg.m_size = 8;
        msg.m_10 = 8;
        for (Elem_002AFF30* x = func_002A53F8(t, &it, 0); x; x = func_002A5490(t, &it, 0)) {
            func_001FF970(m10, func_002B3080(x), &msg);
        }
    }
    return 1;
}
