extern "C" void func_00107E10(void* p);

struct Base_001BAC68 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6(int on);
};

struct Obj_001BAC68 : Base_001BAC68 {
    int m1C;
    char pad20[0x38 - 0x20];
    void* m38;
    void Method();
};

void Obj_001BAC68::Method()
{
    if (!m1C) {
        m1C = 1;
        V6(0);
        if (m38)
            func_00107E10(m38);
    }
}
