struct Msg_002AEB90 {
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

struct Sk_002AEB90 {
    char pad[0x3B0];
    unsigned int m3B0;
};

struct Heap_002AEB90 {
    char pad[0xDC];
    int mDC;
};

struct Mgr_002AEB90 {
    char pad[0x9C];
    void* m9C;
};

extern Sk_002AEB90* D_0038FC78;
extern Heap_002AEB90* D_00388A70;
extern int D_00391ED8;
extern "C" Msg_002AEB90* func_001FA800(Msg_002AEB90* m);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7360(void* s, int a, unsigned int name);
extern "C" void func_001048F0(void* p);
extern "C" void func_002A8250(Mgr_002AEB90* s, int v);
extern "C" void func_001F0210(unsigned int name, void* p, int a, int b, int c);
extern "C" void func_00200C00(void* q, Msg_002AEB90* m);
extern "C" void func_0010A950(Heap_002AEB90* p, int v);
extern "C" void func_0010A9B0(Heap_002AEB90* p);
extern "C" void* func_0029C320();
extern "C" void func_0029A2F0(void* p, int v);
extern "C" void func_0029A3B8(void* p);

struct Obj_002AEB90 {
    int m0;
    char pad4[0xC];
    void* m10;
    int m14;
    int m18;
    Mgr_002AEB90* m1C;
    int Handle();
};

int Obj_002AEB90::Handle()
{
    Mgr_002AEB90* mgr = m1C;
    if (m18 & 4) {
        Sk_002AEB90* sk = D_0038FC78;
        Msg_002AEB90 msg;
        func_001FA800(&msg);
        if (sk->m3B0 == 0x9F2BAFB7) {
            void* p = func_001E6978(func_001190D0(8));
            func_001E7360(p, 0, 0x19ECA78E);
            func_001048F0(mgr->m9C);
            func_002A8250(mgr, 2);
            func_001F0210(0x60B653DB, p, 0, 0, 0);
            if (p)
                func_001E6AE8(p, 3);
            return 4;
        }
        msg.m_type = 0x8B;
        msg.m_C = 2;
        msg.m_10 = 8;
        func_00200C00(m10, &msg);
        return 3;
    }
    func_0010A950(D_00388A70, D_00388A70->mDC);
    func_0029A2F0(func_0029C320(), m0);
    D_00391ED8 = 0;
    func_0029A3B8(func_0029C320());
    D_00391ED8 = 1;
    func_0010A9B0(D_00388A70);
    return 1;
}
