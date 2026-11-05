struct Tgt_001D1BD0 {
    char pad0[0x20];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int a);
};

struct Obj_001D1BD0 {
    char pad0[0x24];
    Tgt_001D1BD0* m24;
    void Call(int a);
};

void Obj_001D1BD0::Call(int a)
{
    m24->v4(a);
}
