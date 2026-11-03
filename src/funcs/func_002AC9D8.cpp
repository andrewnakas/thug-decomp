struct Msg_002AC9D8 {
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

struct Conn_002AC9D8 {
    char pad[0x48];
    int m48;
};

struct Item_002AC9D8 {
    char pad[0x18];
    void* m18;
    char pad2[0x14C - 0x1C];
    int m14C;
};

struct Mgr_002AC9D8 {
    char pad[0x14];
    int m14;
    char pad2[0x1A8 - 0x18];
    Item_002AC9D8* m1A8;
};

extern void* D_0038FC78;
extern "C" Item_002AC9D8* func_002A5248(Mgr_002AC9D8* s, Conn_002AC9D8* id);
extern "C" int func_002B1FE8(Item_002AC9D8* e);
extern "C" int func_002B1FC8(Item_002AC9D8* e);
extern "C" int func_002B1FD8(Item_002AC9D8* e);
extern "C" void func_002B22A0(Item_002AC9D8* e);
extern "C" int func_002A3B50(Mgr_002AC9D8* m);
extern "C" int func_002A1FF0(Mgr_002AC9D8* m);
extern "C" void func_002A5A88(Mgr_002AC9D8* m, Item_002AC9D8* s, int a);
extern "C" void func_0022CF98(void* a, void* b);
extern "C" void func_002A4C78(Mgr_002AC9D8* s);
extern "C" Item_002AC9D8* func_002A49B8(Mgr_002AC9D8* p);
extern "C" void func_002A4A58(Mgr_002AC9D8* p, Item_002AC9D8* v);
extern "C" Msg_002AC9D8* func_001FA800(Msg_002AC9D8* m);
extern "C" void func_001FF970(int q, int id, Msg_002AC9D8* m);

struct Obj_002AC9D8 {
    char pad[0x14];
    Conn_002AC9D8* m14;
    char pad18[4];
    Mgr_002AC9D8* m1C;
    int Handle();
};

int Obj_002AC9D8::Handle()
{
    Msg_002AC9D8 msg;
    Mgr_002AC9D8* mgr = m1C;
    void* g = D_0038FC78;
    Item_002AC9D8* it = func_002A5248(mgr, m14);
    if (it && !func_002B1FE8(it)) {
        if (!func_002B1FC8(it) && func_002A3B50(mgr) >= func_002A1FF0(mgr)) {
            func_001FA800(&msg);
            msg.m_type = 0x4E;
            func_001FF970(mgr->m14, m14->m48, &msg);
        } else {
            func_001FA800(&msg);
            if (!func_002B1FC8(it)) {
                void* x = it->m18;
                func_002A5A88(mgr, it, 2);
                func_0022CF98(g, x);
                it->m18 = 0;
                it->m14C |= 4;
                if (func_002B1FD8(it)) {
                    func_002B22A0(it);
                    func_002A4C78(mgr);
                }
                if (it == mgr->m1A8) {
                    mgr->m1A8 = func_002A49B8(mgr);
                    if (it == mgr->m1A8)
                        mgr->m1A8 = 0;
                    func_002A4A58(mgr, mgr->m1A8);
                }
            }
            msg.m_type = 0x4D;
            func_001FF970(mgr->m14, m14->m48, &msg);
        }
        return 1;
    }
    return 3;
}
