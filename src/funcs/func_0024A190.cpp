struct Base_0024A190 {
    char pad[0x14];
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual int IsDone();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual int IsActive();
};

struct Obj_0024A190;
extern "C" void func_0024A220(Obj_0024A190* self);
extern "C" void func_002451B0(Obj_0024A190* self);

struct Obj_0024A190 : Base_0024A190 {
    void Run();
};

void Obj_0024A190::Run()
{
    if (IsDone() && IsActive()) {
        func_0024A220(this);
    }
    func_002451B0(this);
}
