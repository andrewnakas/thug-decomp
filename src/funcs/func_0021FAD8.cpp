extern void* D_00392068;
extern void* D_0038FC78;
extern "C" int func_002A1A38(void* p);
extern "C" int func_002A7EE0(void* p);
extern "C" void func_002313E0(void* p, int v);

extern "C" int func_0021FAD8()
{
    void* s = D_00392068;
    if (func_002A1A38(s)) {
        func_002313E0(D_0038FC78, 1);
        return 1;
    }
    return func_002A7EE0(s);
}
