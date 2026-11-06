class Base_001404C8 {
public:
    int m_0;
    int m_4;
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void Run(int v);
};

class Obj_001404C8 : public Base_001404C8 {
public:
    char pad[0x1DC - 0xC];
    int m_1DC;
    void Set(int v);
};

void Obj_001404C8::Set(int v)
{
    m_1DC = v;
    Run(v);
}
