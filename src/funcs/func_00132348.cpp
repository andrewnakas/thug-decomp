extern "C" int func_00139B30(int a, int b, int c, int d, int e, int f, int g);
extern "C" void func_0010BFC0(void* ctx);
extern "C" void func_0010BFC8();
extern "C" int func_001462D8(int a, int b, int c, int d, int e, int f, int g, int h);

extern char D_0035D4D0[];

int func_00132348(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
    int x = func_00139B30(e, f, g, 0, h, i, 0);
    func_0010BFC0(D_0035D4D0);
    int r = func_001462D8(a, b, c, d, x, h, i, j);
    func_0010BFC8();
    return r;
}
