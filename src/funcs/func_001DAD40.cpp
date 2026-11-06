extern void* D_00388A70;
extern int D_0038DF18;
extern void* D_004686C8[];
extern "C" void* func_0010A638(void* pool, int size, int a, int b);
extern "C" void* func_001DA890(void* p);

extern "C" void* func_001DAD40()
{
    void** slot = &D_004686C8[D_0038DF18];
    *slot = func_001DA890(func_0010A638(D_00388A70, 0xFD0, 1, 0));
    return D_004686C8[D_0038DF18++];
}
