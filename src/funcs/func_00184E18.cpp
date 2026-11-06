extern char D_00361980[];
extern "C" int func_00103F28(const char* fmt, ...);

class Base_00184E18 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2(int a);
};

class Obj_00184E18 : public Base_00184E18 {
public:
    void Fn(int a);
};

void Obj_00184E18::Fn(int a)
{
    func_00103F28(D_00361980);
    V2(a);
}
