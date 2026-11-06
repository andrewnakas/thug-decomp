struct Rgba_00135DF0 {
    unsigned char r, g, b, a;
};

struct State_00135DF0 {
    Rgba_00135DF0 m0;
    int m4[19];
};

extern State_00135DF0 D_003BEB00;
extern "C" void func_0014ABD0();

extern "C" void func_00135DF0(Rgba_00135DF0* c)
{
    D_003BEB00.m0 = *c;
    func_0014ABD0();
}
