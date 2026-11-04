struct Target_001D1778 {
    int m_pad[0x494 / 4];
    virtual void Signal(int v);
};

struct Obj_001D1778 {
    int m_pad[8];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10(int v);
    virtual Target_001D1778* V11();
    int Run();
};

int Obj_001D1778::Run()
{
    Target_001D1778* t = V11();
    if (t) {
        t->Signal(3);
        V10(0);
    }
    return 0;
}
