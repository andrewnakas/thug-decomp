struct Data_002317A0 {
    signed char m_type;
    unsigned char m_player;
    char pad2[2];
    int m4;
    int m8;
    int mC;
    char m10[4];
};

struct Msg_002317A0 {
    Data_002317A0* m_data;
    char pad4[0x10];
    int m14;
};

struct Conn_002317A0 {
    char pad0[0x18];
    void* m18;
};

extern void* D_00392068;
extern "C" Conn_002317A0* func_002A5248(void* mgr, int id);
extern "C" void* func_00203360(void* p);
extern "C" unsigned char func_002A7660(void* mgr);
extern "C" void func_002394C8(void* p, int a, int b, int c, char* d, int e);

int func_002317A0(Msg_002317A0* msg)
{
    Data_002317A0* d = msg->m_data;
    void* mgr = D_00392068;
    Conn_002317A0* c = func_002A5248(mgr, msg->m14);
    if (!c) return 3;
    void* p = func_00203360(c->m18);
    if (d->m_type == 1) {
        Data_002317A0* e = msg->m_data;
        if (e->m_player == func_002A7660(mgr)) {
            func_002394C8(p, e->m4, e->m8, e->mC, e->m10, 1);
        }
    }
    return 1;
}
