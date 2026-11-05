struct Base_002453C8 {
    char pad[0x14];
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
    virtual int V11(int a, int b);
};

struct Item_002453C8 : Base_002453C8 {
    char pad18[0x88 - 0x18];
    int m_88;
    void Run();
};

extern "C" int func_00248800(Item_002453C8* self, unsigned int name);

void Item_002453C8::Run()
{
    func_00248800(this, 0xD34EB52B);
    if (m_88) {
        V11(0, 1);
    }
}
