extern "C" void* func_001391B0(void* a, void* b);
extern "C" void* func_00138738(void* e, void* c);

void* Get_00139368(void* a, void* b, void* c)
{
    void* e = func_001391B0(a, b);
    if (e)
        return func_00138738(e, c);
    return 0;
}
