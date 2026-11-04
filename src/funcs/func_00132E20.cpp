extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);
extern "C" void func_0010DCD0(void* o);

struct ElemBase_00132E20 {
    char pad[0xC];
    virtual ~ElemBase_00132E20();
};

struct Elem_00132E20 : ElemBase_00132E20 {
    int m10;
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Node_00132E20 {
    int m0;
    int m4;
    int m8;
    Node_00132E20* mC;
    int m10;
    virtual ~Node_00132E20();
    Node_00132E20* Next()
    {
        Node_00132E20* n = mC;
        if (n->m4 != -1)
            return n;
        return 0;
    }
};

struct Scene_00132E20 {
    char pad0[0x1E8];
    char m_1E8[0x84];
    Elem_00132E20* m_26C;
    int m_270;
    int m_274;
    Node_00132E20* m_278;
    Node_00132E20* m_27C;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual int V6();
    int Unload();
};

extern "C" void func_00133170(Scene_00132E20* self);
extern "C" void func_00133418(Scene_00132E20* self, int id);

int Scene_00132E20::Unload()
{
    if (m_274) {
        func_00133170(this);
    }
    if (!V6()) {
        return 0;
    }
    delete[] m_26C;
    if (m_270) {
        func_0010DCD0(m_1E8);
    }
    if (m_278) {
        Node_00132E20* p = m_278->Next();
        while (p) {
            Node_00132E20* n = p->Next();
            delete p;
            p = n;
        }
    }
    if (m_27C) {
        Node_00132E20* p = m_27C->Next();
        while (p) {
            Node_00132E20* n = p->Next();
            func_00133418(this, p->m4);
            delete p;
            p = n;
        }
    }
    m_274 = 0;
    return 1;
}
