extern "C" void func_00291130(void* p, void* a, void* b);

struct Obj_001AFDC8 {
    int m_pad[199];
    int m31C;
};

struct Base_001AFDC8 {
    int m_pad[3];
    Obj_001AFDC8* mC;
    int m10[2];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void Suspend(int on);
};

struct C_001AFDC8 : Base_001AFDC8 {
    int m1C[3];
    void* m28;
    int m2C[652];
    int mA5C;
    int mA60;
    void Update();
};

extern "C" void func_001AF5D8(C_001AFDC8* self);
extern "C" void func_001AEB48(C_001AFDC8* self);
extern "C" void func_001AE488(C_001AFDC8* self);
extern "C" void func_001AE868(C_001AFDC8* self);
extern "C" void func_001AE910(C_001AFDC8* self);
extern "C" void func_001AF298(C_001AFDC8* self);
extern "C" void func_001AF328(C_001AFDC8* self);
extern "C" void func_001AFBF8(C_001AFDC8* self);

void C_001AFDC8::Update()
{
    if (!mC->m31C) {
        Suspend(1);
        return;
    }
    func_001AF5D8(this);
    func_00291130(m28, &mA5C, &mA60);
    func_001AEB48(this);
    func_001AE488(this);
    func_001AE868(this);
    func_001AE910(this);
    func_001AF298(this);
    func_001AF328(this);
    func_001AFBF8(this);
}
