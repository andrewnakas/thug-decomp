extern "C" void* func_0022E358(int a);
extern "C" int func_0024F938(void* a);
extern "C" int func_001F0D78(char* name);
extern "C" void func_00243FB0();
extern "C" int func_00250428();
extern "C" int func_002451B0(void* self);
extern int D_0038FC78;
extern char D_003741B0[];

struct Base_0024B7A8 {
    char pad0[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int Ready();
    virtual void V4();
    virtual void Fire();
};

struct Obj_0024B7A8 : Base_0024B7A8 {
    char pad18[0xA4 - 0x18];
    int m_A4;
    int Update();
};

int Obj_0024B7A8::Update()
{
    int g = D_0038FC78;
    if (!m_A4) {
        func_00243FB0();
        m_A4 = 1;
    }
    int mode = func_0024F938(func_0022E358(g));
    if (mode == func_001F0D78(D_003741B0) && func_00250428() && Ready()) {
        Fire();
        return 1;
    }
    return func_002451B0(this);
}
