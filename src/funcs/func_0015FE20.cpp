struct Rgba_0015FE20 {
    unsigned char r, g, b, a;
};

extern "C" void func_0015FC40(int a, Rgba_0015FE20* c, int n, int b, void* self);

void Draw_0015FE20(void* self, int a, int b)
{
    Rgba_0015FE20 c;
    c.r = 0;
    c.g = 0;
    c.b = 0;
    c.a = 0;
    func_0015FC40(a, &c, 5, b, self);
}
