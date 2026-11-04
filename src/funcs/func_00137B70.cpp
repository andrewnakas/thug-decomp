class Obj00137B70 {
public:
    char pad[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void Target(int a0, int a1);
    void Call(int a0, int a1);
};

void Obj00137B70::Call(int a0, int a1)
{
    Target(a0, a1);
}
