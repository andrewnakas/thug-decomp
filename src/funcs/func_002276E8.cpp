extern void* D_00388EFC;
extern "C" void* func_00112FB8(void* a, int b, int c);
extern "C" int func_00113198(void* p);

extern "C" int func_002276E8()
{
    void* p = func_00112FB8(D_00388EFC, 0, 0);
    if (p) return func_00113198(p);
    return 0;
}
