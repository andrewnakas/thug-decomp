class Obj_00144D30 {
public:
    char pad[0xA18];
    virtual void V0();
    virtual int V1(int a, int b, int c, int d);
    void Call(int a, int b, int c, int d);
};

void Obj_00144D30::Call(int a, int b, int c, int d)
{
    V1(a, b, c, d);
}
