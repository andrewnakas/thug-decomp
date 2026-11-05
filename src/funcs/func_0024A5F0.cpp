struct Base_0024A5F0 {
    char pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V1b();
    virtual int V2();
};

struct Obj_0024A5F0 : Base_0024A5F0 {
    char pad18[0x94];
    int mAC;
    bool Fn(int id);
};

bool Obj_0024A5F0::Fn(int id)
{
    bool r = false;
    if (id == mAC) r = V2() != 0;
    return r;
}
