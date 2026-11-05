struct Base_0024A6B8 {
    char pad[0x14];
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual int Va();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual int Vb();
};

struct Obj_0024A6B8 : Base_0024A6B8 {
    char pad18[0x94];
    int mAC;
    int Fn(int id);
};

int Obj_0024A6B8::Fn(int id)
{
    if (Va() && mAC == id) return Vb();
    return 0;
}
