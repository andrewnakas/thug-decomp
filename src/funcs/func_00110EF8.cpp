extern int D_0038881C;
extern "C" int func_001092D0();
extern "C" int func_001092E0();
extern "C" int func_001093F8(void* f, int a);
extern "C" int func_00110570(void* f);
extern "C" int func_00110050(void* f);
extern "C" int func_00110EF8(void* f)
{
    if (func_001092D0()) {
        int r = func_001093F8(f, 0);
        if (func_001092E0()) {
            return r;
        }
    }
    if (D_0038881C) {
        return func_00110050(f);
    }
    return func_00110570(f);
}
