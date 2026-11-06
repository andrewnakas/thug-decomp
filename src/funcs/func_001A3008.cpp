typedef int qword_001A3008 __attribute__((mode(TI)));
union Vec_001A3008 {
    qword_001A3008 q;
    struct { float x, y, z, w; } f;
};
struct Sub_001A3008 {
    char pad[0x50];
    Vec_001A3008 m50;
};
extern "C" void func_001A3660(void* p);
struct Obj_001A3008 {
    int m0, m4, m8;
    Sub_001A3008* mC;
    char pad[0xA0 - 0x10];
    Vec_001A3008 mA0;
    Vec_001A3008 mB0;
    void Run();
};

void Obj_001A3008::Run()
{
    mB0 = mA0;
    mA0 = mC->m50;
    func_001A3660(this);
}
