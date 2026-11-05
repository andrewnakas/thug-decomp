extern "C" void func_00248800(void* p, unsigned int crc);

struct Base_00244DF0 {
    int m_pad[5];
    virtual ~Base_00244DF0();
    virtual void V1();
    virtual void V2();
    virtual bool V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11(int a, int b);
};

struct Obj_00244DF0 : Base_00244DF0 {
    int m18[10];
    int m40;
    bool Run();
};

bool Obj_00244DF0::Run()
{
    if (V3()) {
        m40++;
        func_00248800(this, 0x79D8D4B6);
        V11(1, 1);
        return true;
    }
    return false;
}
