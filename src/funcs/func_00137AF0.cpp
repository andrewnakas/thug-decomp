class Obj00137AF0 {
public:
    char pad[0x18];
    virtual void V0();
    virtual void V1();
    virtual int Target(int a0, int a1);
    int Call(int a0, int a1);
};

int Obj00137AF0::Call(int a0, int a1)
{
    return Target(a0, a1);
}
