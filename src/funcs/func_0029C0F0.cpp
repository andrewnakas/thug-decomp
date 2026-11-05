extern "C" void* func_0029C070(void* a, void* b);
extern "C" void func_00299F38(void* p, int v);

extern "C" void func_0029C0F0(void* a, void* b, int v)
{
    void* p = func_0029C070(a, b);
    if (p)
        func_00299F38(p, v);
}
