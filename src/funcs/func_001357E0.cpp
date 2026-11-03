class Obj001357E0 {
public:
    char pad[0x4];
    virtual void V0();
    virtual void V1();
    virtual void Target(int a0, int a1);
    void Call(int a0, int a1);
};

void Obj001357E0::Call(int a0, int a1)
{
    Target(a0, a1);
}
