extern "C" void func_00107FB0(void* p);
extern "C" void func_00107D80(void* p);

struct Base_001BACC8 {
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

struct Obj_001BACC8 : Base_001BACC8 {
    int m1C;
    char pad20[0x38 - 0x20];
    void* m38;
    void Method();
};

void Obj_001BACC8::Method()
{
    if (m1C) {
        m1C = 0;
        V6(1);
        if (m38) {
            func_00107FB0(m38);
            func_00107D80(m38);
        }
    }
}
