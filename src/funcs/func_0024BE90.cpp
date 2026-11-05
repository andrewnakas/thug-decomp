struct Base_0024BE90 {
    char pad[0x14];
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual bool Va();
};

struct Obj_0024BE90;
extern "C" void func_0024C428(Obj_0024BE90* self);
extern "C" bool func_00244620(Obj_0024BE90* self);

struct Obj_0024BE90 : Base_0024BE90 {
    bool Fn();
};

bool Obj_0024BE90::Fn()
{
    if (!Va()) {
        func_0024C428(this);
        return func_00244620(this);
    }
    return false;
}
