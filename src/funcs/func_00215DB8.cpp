extern void* D_00392068;
extern "C" int func_002B5688(void* o);
extern "C" void func_002B5680(void* o, int v);
extern "C" void func_002B5608(void* o, int v);

bool func_00215DB8(void* params, void* script)
{
    void* o = D_00392068;
    if (func_002B5688(o) == 2) {
        func_002B5680(o, 10);
        func_002B5608(o, 1);
    } else {
        func_002B5608(o, 10);
    }
    return true;
}
