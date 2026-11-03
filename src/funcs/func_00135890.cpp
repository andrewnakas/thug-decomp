class Obj00135890 {
public:
    char pad[0x4];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void Target(int a0, int a1, int a2);
    void Call(int a0, int a1, int a2);
};

void Obj00135890::Call(int a0, int a1, int a2)
{
    Target(a0, a1, a2);
}
