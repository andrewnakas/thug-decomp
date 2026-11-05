struct Tgt_001D1CA0 {
    char pad0[0x20];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int a);
};

struct Obj_001D1CA0 {
    char pad0[0x24];
    Tgt_001D1CA0* m24;
    void Call(int a);
};

void Obj_001D1CA0::Call(int a)
{
    m24->v10(a);
}
