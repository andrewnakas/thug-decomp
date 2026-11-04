extern int D_0038881C;
extern "C" int func_001092D0(void* a);
extern "C" int func_001092E8(void* a);
extern "C" int func_001092E0();
extern "C" int func_00110098(void* a);
extern "C" int func_001105C8(void* a);

extern "C" int func_00110DC8(void* a)
{
    if (func_001092D0(a)) {
        int r = func_001092E8(a);
        if (func_001092E0()) {
            return r;
        }
    }
    if (D_0038881C) {
        return func_00110098(a);
    }
    return func_001105C8(a);
}
