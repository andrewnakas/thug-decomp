extern "C" void* func_001393A8(void* mgr, int a, int b);
extern "C" void func_00138970(void* o, int c, int d);

extern "C" void* func_00139410(void* mgr, int a, int b, int c, int d)
{
    void* o = func_001393A8(mgr, a, b);
    if (o) {
        func_00138970(o, c, d);
    }
    return o;
}
