extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;
extern void* D_0038A8C4;

void Free_001483B0()
{
    if (D_0038A8C4)
        func_0010A8D8(D_00388A70, D_0038A8C4);
    D_0038A8C4 = 0;
}
