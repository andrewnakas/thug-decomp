struct Base_0024B2B8 {
    char pad[0x14];
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
    virtual int Va();
};

struct Obj_0024B2B8 : Base_0024B2B8 {
    char pad18[0x60];
    int m78;
    char pad7C[0x2C];
    int mA8;
    int mAC;
    int mB0;
    bool Fn();
};

bool Obj_0024B2B8::Fn()
{
    m78 = 0;
    mB0 = 0;
    mAC = 0;
    if (Va()) {
        mA8 = 0;
        return true;
    }
    return false;
}
