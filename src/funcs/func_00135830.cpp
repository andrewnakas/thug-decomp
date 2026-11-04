class Obj00135830 {
public:
    char pad[0x4];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Target(int a0);
    void Call(int a0);
};

void Obj00135830::Call(int a0)
{
    Target(a0);
}
