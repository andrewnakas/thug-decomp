struct Obj_0024BBF8;
extern "C" void func_00248800(Obj_0024BBF8* self, unsigned int name);

struct Base_0024BBF8 {
    char pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V1b();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10(int a, int b);
};

struct Obj_0024BBF8 : Base_0024BBF8 {
    void Fn();
};

void Obj_0024BBF8::Fn()
{
    func_00248800(this, 0xD34EB52B);
    V10(0, 1);
}
