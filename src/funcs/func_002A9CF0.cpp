extern void* D_00392068;
extern "C" void func_002B5680(void* p, int v);
extern "C" void func_002B5608(void* p, int v);

extern "C" bool func_002A9CF0()
{
    void* m = D_00392068;
    func_002B5680(m, 3);
    func_002B5608(m, 1);
    return true;
}
