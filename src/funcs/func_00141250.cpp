extern "C" void* func_001324B0();
extern "C" void* func_001414D0(void* mgr, int* id, int a);

extern "C" void* func_00141250(int id)
{
    void* r = 0;
    if (func_001324B0()) {
        r = func_001414D0(func_001324B0(), &id, 1);
    }
    return r;
}
