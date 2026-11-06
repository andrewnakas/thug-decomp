struct Model_0019FAB8 {
    char pad0[0x14];
    void* m14;
};

struct Obj_0019FAB8 {
    char pad0[0xC];
    Model_0019FAB8* mC;
    char pad10[0x34 - 0x10];
    int m34;
    int m38;
    char pad3C[0x40 - 0x3C];
    int m40;
    char pad44[0x50 - 0x44];
    int m50;
    int m54;
    int m58;
    void Fn();
};

extern "C" void func_001A2728(Obj_0019FAB8* self);
extern "C" void func_001EE608(void* p);

void Obj_0019FAB8::Fn()
{
    func_001A2728(this);
    m34 = 0;
    m38 = 0;
    if (m54) {
        m54 = 0;
        if (mC->m14)
            func_001EE608(mC->m14);
    }
    m58 = 0;
    m50 = 0;
    m40 = 0;
}
