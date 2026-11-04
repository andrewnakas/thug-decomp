extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Owned_0029F318 {
    int m0[6];
    virtual void A();
    virtual void B();
    virtual ~Owned_0029F318();
};

struct SysA_0029F318 { ~SysA_0029F318(); };
struct SysB_0029F318 { ~SysB_0029F318(); };
struct SysC_0029F318 { ~SysC_0029F318(); };
struct SysD_0029F318 { ~SysD_0029F318(); };

struct List_0029F318 {
    int m0[4];
    ~List_0029F318();
};

#define NODE(N) \
struct N { \
    int m0; \
    void* m_data; \
    int m8; \
    N* m_next; \
    N* m_prev; \
    virtual void Key(); \
    virtual ~N() \
    { \
        m_prev->m_next = m_next; \
        m_next->m_prev = m_prev; \
        m_next = this; \
        m_prev = this; \
    } \
};

NODE(NodeA_0029F318)
NODE(NodeB_0029F318)
NODE(NodeC_0029F318)
NODE(NodeD_0029F318)

struct Obj_0029F318 {
    int m0;
    SysA_0029F318* m4;
    SysB_0029F318* m8;
    SysC_0029F318* mC;
    SysD_0029F318* m10;
    char pad14[0x78 - 0x14];
    Owned_0029F318* m78;
    Owned_0029F318* m7C;
    int m80;
    Owned_0029F318* m84;
    Owned_0029F318* m88;
    Owned_0029F318* m8C;
    int m90;
    int m94;
    Owned_0029F318* m98;
    Owned_0029F318* m9C;
    Owned_0029F318* mA0;
    Owned_0029F318* mA4;
    Owned_0029F318* mA8;
    char padAC[0xBC - 0xAC];
    List_0029F318 mBC;
    List_0029F318 mCC;
    NodeD_0029F318 mDC;
    NodeC_0029F318 mF4;
    NodeB_0029F318 m10C;
    NodeA_0029F318 m124;
    NodeA_0029F318 m13C;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_0029F318();
};

Obj_0029F318::~Obj_0029F318()
{
    delete m4;
    delete m8;
    delete mC;
    delete m10;
    delete m88;
    delete m84;
    delete m78;
    delete m7C;
    delete m8C;
    delete m98;
    delete m9C;
    delete mA0;
    delete mA4;
    delete mA8;
}
