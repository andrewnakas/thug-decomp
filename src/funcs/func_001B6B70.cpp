struct Inner_001B6B70 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
};

struct Obj_001B6B70 {
    char pad[0x1C];
    Inner_001B6B70* m1C;
    void Method(int on);
};

void Obj_001B6B70::Method(int on)
{
    if (m1C) {
        if (on)
            m1C->V4();
        else
            m1C->V5();
    }
}
