struct Base_0024DE60 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual int SetState(int a, int b);
};

struct Obj_0024DE60;
extern "C" int func_0024E048(Obj_0024DE60* self);
extern "C" int func_0024E0C0(Obj_0024DE60* self);
extern "C" void func_00244DF0(Obj_0024DE60* self);
extern "C" int func_0024DF20(Obj_0024DE60* self);
extern "C" void* func_00240850();
extern "C" int func_00246258(Obj_0024DE60* self);
extern "C" void func_0023BD18(void* a, int b);
extern "C" void func_00248800(Obj_0024DE60* self, unsigned int name);

struct Obj_0024DE60 : Base_0024DE60 {
    char pad18[0x10];
    int m28;

    void Update();
};

void Obj_0024DE60::Update()
{
    if (func_0024E048(this) || func_0024E0C0(this)) {
        func_00244DF0(this);
        return;
    }
    if (func_0024DF20(this)) {
        void* a = func_00240850();
        func_0023BD18(a, func_00246258(this));
        return;
    }
    func_00248800(this, 0xD34EB52B);
    if (m28 != 2) SetState(0, 1);
}
