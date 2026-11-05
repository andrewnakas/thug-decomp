extern "C" void func_0013C640(void* p, int a);

struct A_00135160 {
    char pad[0xC];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5(int a);
};

struct C_00135160 {
    int m0;
    unsigned int m4;
    char pad8[0x18];
    void* m20;
    A_00135160* m24;
    void Apply(int a);
};

void C_00135160::Apply(int a)
{
    if (m24) {
        m24->V5(a);
        if (m4 & 0x40)
            m4 |= 0x20;
    }
    if (m20)
        func_0013C640(m20, a);
}
