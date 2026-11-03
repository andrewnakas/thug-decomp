extern char D_00371C78[];

struct Iter_002AF770 {
    int m0;
    int m4;
    void* m8;
    Iter_002AF770() { m4 = 0; m8 = D_00371C78; }
    ~Iter_002AF770() { m8 = D_00371C78; }
};

struct Msg_002AF770 {
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

struct D1_002AF770 {
    unsigned char v;
};

struct Elem_002AF770 {
    char pad0[0x14C];
    unsigned int m14C;
    bool Ready() { return ((unsigned char*)&m14C)[1] & 1; }
    bool Nr() { return !Ready(); }
};

extern "C" Elem_002AF770* func_002A5248(void* s, int id);
extern "C" int func_002A7660(void* s);
extern "C" Elem_002AF770* func_002A53F8(void* self, Iter_002AF770* it, int a);
extern "C" Elem_002AF770* func_002A5490(void* self, Iter_002AF770* it, int a);
extern "C" Msg_002AF770* func_001FA800(Msg_002AF770* m);
extern "C" void* func_002A39D8(void* s);
extern "C" int func_002B3080(Elem_002AF770* o);
extern "C" void func_001FF970(void* q, int id, Msg_002AF770* m);

struct Obj_002AF770 {
    unsigned char* m0;
    char pad4[0x10];
    int m14;
    int m18;
    void* m1C;
    int Handle();
};

int Obj_002AF770::Handle()
{
    void* mgr = m1C;
    Elem_002AF770* e = func_002A5248(mgr, m14);
    unsigned char c[8];
    c[0] = *m0;
    if (e) {
        Iter_002AF770 it;
        if (e->Ready())
            return 3;
        int r = func_002A7660(mgr);
        if (c[0] != r)
            return 3;
        e->m14C |= 0x100;
        bool all = true;
        for (e = func_002A53F8(mgr, &it, 0); e; e = func_002A5490(mgr, &it, 0)) {
            if (e->Nr()) {
                all = false;
                break;
            }
        }
        if (all) {
            Msg_002AF770 msg;
            func_001FA800(&msg);
            void* q = func_002A39D8(mgr);
            msg.m_type = 0x5A;
            msg.m_C = 2;
            msg.m_10 = 8;
            for (e = func_002A53F8(mgr, &it, 1); e; e = func_002A5490(mgr, &it, 1))
                func_001FF970(q, func_002B3080(e), &msg);
        }
    }
    return 1;
}
