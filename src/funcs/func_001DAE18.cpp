extern int D_0038DF18;
extern void* D_004686C8[];
extern "C" void func_001DAC80(void* o, void* p);

void func_001DAE18(void* p)
{
    for (int i = 0; i < D_0038DF18; i++)
        func_001DAC80(D_004686C8[i], p);
}
