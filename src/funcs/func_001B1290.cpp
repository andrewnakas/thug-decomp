struct Obj_001B1290;
extern "C" float func_0010FAB8();
extern "C" void func_001B5150(Obj_001B1290* o);

struct Base_001B1290 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
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
    virtual void V12();
};

struct Obj_001B1290 : Base_001B1290 {
    unsigned int m1C;
    char pad20[0x8C - 0x20];
    float m8C;
    void Method();
};

void Obj_001B1290::Method()
{
    m8C = func_0010FAB8();
    switch (m1C) {
    case 0x69B05E2C:
        V11();
        break;
    case 0xA85AF587:
        V12();
        break;
    case 0x6367167B:
        func_001B5150(this);
        break;
    case 0x82B45A67:
        break;
    }
}
