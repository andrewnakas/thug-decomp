extern "C" void* func_001046B0(int size);
extern "C" void* func_0014CBB8(void* mem, int a1, int a2, int a3, int t0, int t1, int t2, int t3);

extern "C" void* func_001462D8(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3)
{
    return func_0014CBB8(func_001046B0(0xF0), a1, a2, a3, t0, t1, t2, t3);
}
