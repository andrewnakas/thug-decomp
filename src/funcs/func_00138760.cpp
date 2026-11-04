class Obj00138760 {
public:
    char pad[0x8];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual int Target(int a0, int a1);
    int Call(int a0, int a1);
};

int Obj00138760::Call(int a0, int a1)
{
    return Target(a0, a1);
}
