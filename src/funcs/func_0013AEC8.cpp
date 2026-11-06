struct Col_0013AEC8 {
    float r, g, b, a;
};

struct Desc_0013AEC8 {
    int m0;
    float r, g, b, a;
};

extern Col_0013AEC8 D_0035E080[10];
extern int D_004653C0[10];
extern "C" int func_0013B468(Desc_0013AEC8* d, int a);

extern "C" void func_0013AEC8()
{
    for (unsigned int i = 0; i < 10; i++) {
        Desc_0013AEC8 d;
        d.r = D_0035E080[i].r;
        d.g = D_0035E080[i].g;
        d.b = D_0035E080[i].b;
        d.a = D_0035E080[i].a;
        D_004653C0[i] = func_0013B468(&d, 0);
    }
}
