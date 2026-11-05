extern int D_0038881C;
extern "C" int func_001092D0();
extern "C" int func_001092E0();
extern "C" int func_00109458(void* buf, int size, int count, void* f);
extern "C" int func_0010EE40();
extern "C" void func_0010ED38(int a);
extern "C" int func_00110608(void* buf, int size, int count, void* f);
extern "C" int func_001100C0(void* buf, int size, int count, void* f);
extern "C" int func_00110F68(void* buf, int size, int count, void* f)
{
    if (func_001092D0()) {
        int r = func_00109458(buf, size, count, f);
        if (func_001092E0()) {
            return r;
        }
    }
    if (func_0010EE40()) {
        func_0010ED38(1);
    }
    if (D_0038881C) {
        return func_001100C0(buf, size, count, f);
    }
    return func_00110608(buf, size, count, f);
}
