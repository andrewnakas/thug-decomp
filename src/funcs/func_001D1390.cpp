struct Info {
    char pad[0x40];
    int m_flags;
};

struct ElemBase {
    int m_data[8];
};

struct Elem : ElemBase {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual Info* GetInfo();
    int IsFlag17Set();
};

int Elem::IsFlag17Set()
{
    return (GetInfo()->m_flags >> 17) & 1;
}
