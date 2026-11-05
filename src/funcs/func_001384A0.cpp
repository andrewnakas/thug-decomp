struct Rgba_001384A0 {
    unsigned char r, g, b, a;
};

extern Rgba_001384A0 D_00393EE0;
extern Rgba_001384A0 D_00393EE8;
extern Rgba_001384A0 D_00393EF0;

extern "C" void func_001384A0(int on, int key)
{
    if (key == 0xFFFF && on) {
        D_00393EE0.r = 0;
        D_00393EE0.g = 0x4C;
        D_00393EE0.b = 0x81;
        D_00393EE0.a = 0x80;
        D_00393EE8.r = 0xAC;
        D_00393EE8.g = 0xD3;
        D_00393EE8.b = 0x73;
        D_00393EE8.a = 0x80;
        D_00393EF0.r = 0x28;
        D_00393EF0.g = 0x28;
        D_00393EF0.b = 0x28;
        D_00393EF0.a = 0x80;
    }
}
