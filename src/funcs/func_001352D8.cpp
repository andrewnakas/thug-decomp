typedef int qword __attribute__((mode(TI)));

struct Vec_001352D8 {
    qword q;
};

extern "C" void func_0013C6E0(void* p, Vec_001352D8* v);

struct A_001352D8 {
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
    virtual void V18();
    virtual void V19(int a, Vec_001352D8* v);
};

struct C_001352D8 {
    int m0;
    unsigned int m4;
    int m8;
    int mC;
    Vec_001352D8 m10;
    void* m20;
    A_001352D8* m24;
    void SetPos(Vec_001352D8* v);
};

extern "C" int func_001351D0(C_001352D8* self);

void C_001352D8::SetPos(Vec_001352D8* v)
{
    if (m24) {
        m24->V19(func_001351D0(this), v);
        if (m4 & 0x40)
            m4 |= 0x20;
    }
    if (m20)
        func_0013C6E0(m20, v);
    m10 = *v;
}
