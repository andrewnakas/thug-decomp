extern int D_0038881C;
extern "C" int func_001092D0(void* a);
extern "C" int func_00109560(void* a);
extern "C" int func_001092E0();
extern "C" int func_001103E0(void* a);
extern "C" int func_00110978(void* a);

extern "C" int func_00111190(void* a)
{
    if (func_001092D0(a)) {
        int r = func_00109560(a);
        if (func_001092E0()) {
            return r;
        }
    }
    if (D_0038881C) {
        return func_001103E0(a);
    }
    return func_00110978(a);
}
