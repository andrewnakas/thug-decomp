struct Vec_00209A40 {
    float x, y, z, w;
};
struct Line_00209A40 {
    Vec_00209A40 a;
    Vec_00209A40 b;
    void Draw(unsigned int r, unsigned int g, unsigned int b);
};

extern "C" void func_001235E8(Vec_00209A40* a, Vec_00209A40* b, unsigned int c0, unsigned int c1);

void Line_00209A40::Draw(unsigned int r, unsigned int g, unsigned int bl)
{
    unsigned int c = 0xFF000000 | (bl << 16) | (g << 8) | r;
    func_001235E8(&a, &b, c, c);
}
