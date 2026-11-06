struct O_0023CBB0 {
    int m0, m4, m8, mC, m10;
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
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual int V22();
};

struct C_0023CBB0;
extern "C" O_0023CBB0* func_0023BAD8(C_0023CBB0* self, void* p, int a);

struct C_0023CBB0 {
    char m_pad[0x20];
    void* m20;
    int Get();
};

int C_0023CBB0::Get()
{
    if (m20) return func_0023BAD8(this, m20, 1)->V22();
    return 0;
}
