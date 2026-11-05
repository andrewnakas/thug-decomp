class Base_00118350 {
public:
    char pad[0x14];
    virtual void V1();
    virtual void V2();
    virtual int Apply(int a);
};

class Obj_00118350;
extern "C" void func_00118348(Obj_00118350* self, int on);

class Obj_00118350 : public Base_00118350 {
public:
    int m18;
    int m1C;
    int Refresh(int a);
};

int Obj_00118350::Refresh(int a)
{
    if (!m1C) {
        return 0;
    }
    func_00118348(this, 0);
    return Apply(a);
}
