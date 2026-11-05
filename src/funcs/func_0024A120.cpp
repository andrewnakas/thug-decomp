extern "C" void* func_00240850();
extern "C" void func_0023EED8(void* p);
extern "C" void func_00244620(void* self);

class Obj_0024A120 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int V8();
    void Fn();
};

void Obj_0024A120::Fn()
{
    if (!V3() && V8())
        func_0023EED8(func_00240850());
    func_00244620(this);
}
