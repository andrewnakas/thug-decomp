struct Base_002A3870 {
    char pad[0x18];
    virtual void v0();
    virtual void v1();
    virtual ~Base_002A3870();
};

extern void* D_0038EB78;
extern "C" int func_00201288(void* w);
extern "C" void func_001F9400(void* m, void* w);
extern "C" void func_001048F0(void* p);

struct Obj_002A3870;
extern "C" void func_002A8020(Obj_002A3870* o);
extern "C" void func_002AB2E8(Obj_002A3870* o, int a);

struct Obj_002A3870 {
    char pad[0x18];
    void* m18[2];
    char pad2[0x80 - 0x20];
    void* m80;
    char pad3[0x88 - 0x84];
    void* m88;
    void* m8C;
    char pad4[0xA4 - 0x90];
    void* mA4;
    char pad5[0xB4 - 0xA8];
    Base_002A3870* mB4;
    void CloseAll();
};

void Obj_002A3870::CloseAll()
{
    void* m = D_0038EB78;
    for (int i = 0; i < 2; i++) {
        if (m18[i]) {
            if (i == 0 && !func_00201288(m18[0]))
                func_001048F0(m88);
            func_001F9400(m, m18[i]);
            m18[i] = 0;
        }
    }
    if (mB4) {
        delete mB4;
        mB4 = 0;
    }
    func_001048F0(m8C);
    func_001048F0(m80);
    func_001048F0(mA4);
    func_002A8020(this);
    func_002AB2E8(this, 0);
}
