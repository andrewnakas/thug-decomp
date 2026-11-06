class Obj_0013F010 {
public:
    char pad[0x1B0];
    unsigned long m_flags;
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
    virtual void V11();
    virtual int V12(int a);
    int Clear(int a);
};

int Obj_0013F010::Clear(int a)
{
    m_flags &= ~1;
    return V12(a);
}
