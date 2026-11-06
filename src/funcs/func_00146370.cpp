extern "C" void* func_001046B0(int size);
extern "C" void* func_0014CD20(void* mem, int a0, int a1, int a2, int a3, int t0);

extern "C" void* func_00146370(int a0, int a1, int a2, int a3, int t0)
{
    return func_0014CD20(func_001046B0(0xF0), a0, a1, a2, a3, t0);
}
