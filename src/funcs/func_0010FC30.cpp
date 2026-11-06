extern volatile unsigned int D_00388D7C;
extern int D_00388830;

extern "C" int func_0010FC30()
{
    unsigned int frames = D_00388D7C;
    int rate = D_00388830;
    return (int)((float)frames * (1000.0f / (float)rate));
}
