struct Rgba_00125F10 {
    unsigned char r, g, b, a;
    Rgba_00125F10() { r = 0; g = 0; b = 0; a = 0x80; }
};

struct B_00123628 {
    int m0;
    int m4;
    B_00123628();
    virtual void V0();
};

struct C_00125F10 : B_00123628 {
    char padC[0x194];
    int m1A0;
    int m1A4;
    int m1A8;
    char pad1AC[0xC];
    int m1B8;
    int m1BC;
    char pad1C0[8];
    Rgba_00125F10 m1C8;
    int m1CC;
    int m1D0;
    C_00125F10();
    virtual void V0();
};

extern "C" void func_00126E18(C_00125F10* o, int a, int b);
extern "C" void func_00183F08(C_00125F10* o, unsigned int id);

C_00125F10::C_00125F10()
{
    m1A4 = 0;
    m1A8 = 0;
    m1A0 = 0;
    m1B8 = 0;
    m1BC = 0;
    func_00126E18(this, 1, 0);
    m1CC = 0;
    m1D0 = 0;
    func_00183F08(this, 0x5200DFB6);
}
