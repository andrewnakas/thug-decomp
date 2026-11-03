struct Pool_001F92B8 {
    char m_pad[0xF4];
    int mF4;
};
extern Pool_001F92B8* D_00388A70;

struct Node_001F92B8 {
    int m0;
    int m4;
    int m8;
    Node_001F92B8* mC;
    Node_001F92B8* m10;

    void Link(Node_001F92B8* list)
    {
        Node_001F92B8* prev = list->m10;
        mC = list;
        m10 = prev;
        list->m10->mC = this;
        list->m10 = this;
    }
};

struct Mgr_001F92B8 {
    char m_pad[0x1C];
    Node_001F92B8 m1C;
    char m_pad2[0x13C - 0x30];
    char m13C[0x2A0 - 0x13C];
    int m2A0;
};

struct Conn_001F92B8 {
    char m_pad[0x1808];
    Node_001F92B8 m1808;
    char m_pad2[0x1834 - 0x181C];
    int m1834;
    Mgr_001F92B8* m1838;
    char m_pad3[0x1850 - 0x183C];
    int m1850;
    char m_pad4[0x4308 - 0x1854];
    int m4308;
    char m430C[0x40];
    char m_pad5[0x4358 - 0x434C];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual int Start();
};

extern "C" void func_0010A950(Pool_001F92B8*, int);
extern "C" void func_0010A9B0(Pool_001F92B8*);
extern "C" void* func_0010A638(Pool_001F92B8*, int, int, int);
extern "C" int func_001FA588(Mgr_001F92B8*);
extern "C" int func_00326E30(char*);
extern "C" Conn_001F92B8* func_001FBE88(void*, int);
extern "C" void func_00332088(char*, char*, int);
extern "C" int func_00201288(Conn_001F92B8*);
extern "C" void func_001FD780(Conn_001F92B8*, int, int);
extern "C" void func_001F90D0(Mgr_001F92B8*, Conn_001F92B8*);

Conn_001F92B8* func_001F92B8(Mgr_001F92B8* mgr, int type, char* name, unsigned short port, int id, int arg)
{
    func_0010A950(D_00388A70, D_00388A70->mF4);
    if (func_001FA588(mgr))
        id = func_00326E30(mgr->m13C);
    Conn_001F92B8* c = func_001FBE88(func_0010A638(D_00388A70, 0x4370, 1, 0), arg);
    func_00332088(c->m430C, name, 0x40);
    c->m1838 = mgr;
    c->Start();
    c->m4308 = type;
    c->m1850 = 1;
    c->m1808.Link(&mgr->m1C);
    if (!func_00201288(c))
        func_001FD780(c, id, port);
    func_001F90D0(mgr, c);
    mgr->m2A0++;
    func_0010A9B0(D_00388A70);
    return c;
}
