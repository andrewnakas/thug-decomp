struct Target_001D1D00 {
    char pad[0x20];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(int v);
};
struct Obj_001D1D00 {
    char pad[0xC];
    char mC;
    char pad2[0x17];
    Target_001D1D00* m24;
    void Set(int v);
};

void Obj_001D1D00::Set(int v)
{
    mC = v;
    m24->v12(v);
}
