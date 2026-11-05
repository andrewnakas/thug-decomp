struct Base_0024A280 {
    char pad[0x14];
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual int Va();
};

struct Obj_0024A280 : Base_0024A280 {
    char pad18[0x3C];
    int m54;
    bool Fn(int s);
};

bool Obj_0024A280::Fn(int s)
{
    if (Va()) {
        m54 += s * 1000;
        return true;
    }
    return false;
}
