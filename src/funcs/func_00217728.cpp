extern "C" void* func_0022BFE0();
extern "C" void* func_0022BEE0(void* p);
extern "C" bool func_001E8398(void* params, int name, int* out, int assert);
extern "C" bool func_001E8870(void* params, int name, int* out, int assert);
extern "C" void func_00255E98(void* p, int a, int b);

bool Cmd_00217728(void* params, void* script)
{
    void* a = func_0022BFE0();
    if (a) {
        void* b = func_0022BEE0(a);
        if (b) {
            int x;
            int y;
            if (func_001E8398(params, 0, &x, 0) && func_001E8870(params, 0, &y, 0))
                func_00255E98(b, y, x);
        }
    }
    return true;
}
