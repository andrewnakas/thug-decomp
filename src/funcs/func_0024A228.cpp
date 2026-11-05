struct Base_0024A228 {
    char pad[0x14];
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual int Vb();
};

struct Obj_0024A228 : Base_0024A228 {
    char pad18[0x3C];
    int m54;
    bool Fn();
};

bool Obj_0024A228::Fn()
{
    bool r = false;
    if (Vb()) r = m54 < 1;
    return r;
}
