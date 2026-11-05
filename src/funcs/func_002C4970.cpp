extern void* D_00392808;
extern int D_0039280C;
extern "C" void* func_00104760(int size, int a, int b);
extern "C" void* func_002C4A18(void* p);

extern "C" void* func_002C4970(int create)
{
    if (!D_00392808 && create)
        D_00392808 = func_002C4A18(func_00104760(0xC0, 0, 1));
    D_0039280C++;
    return D_00392808;
}
