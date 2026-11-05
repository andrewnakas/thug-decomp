extern "C" void func_0013C6B8(void* p, int a);

struct A_00135220 {
    char pad[0xC];
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
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18(int a, int b);
};

struct C_00135220 {
    int m0;
    unsigned int m4;
    int m8;
    int mC;
    char pad10[0x10];
    void* m20;
    A_00135220* m24;
    void SetTime(int t);
};

extern "C" int func_001351D0(C_00135220* self);

void C_00135220::SetTime(int t)
{
    int base = mC - 4;
    int d = (t - base) % 4;
    if (m24)
        m24->V18(func_001351D0(this), d);
    if (m20)
        func_0013C6B8(m20, d);
    mC = t;
}
