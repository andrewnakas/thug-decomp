extern int D_00393ED4;
extern unsigned char D_003BD850[];

extern "C" int func_00113E98(unsigned char* dst)
{
    for (int i = 0; i < D_00393ED4; i++) {
        dst[i] = D_003BD850[i];
    }
    return D_00393ED4;
}
