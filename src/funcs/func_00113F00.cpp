extern "C" int func_00318F08(void* p, int a);
extern "C" int func_00318FE0(void* p, int a);
extern "C" void func_003191C8(int a, int* result);
extern "C" void func_003190E0(void* p, int a, int b);
extern "C" void func_00319128(void* p, int a);
extern "C" void func_00319178(void* p, int a);

extern "C" void func_00113F00(void* p)
{
    int r;
    r = func_00318F08(p, 1);
    if (r == 0) {
        func_003191C8(0, &r);
    }
    r = func_00318FE0(p, 1);
    if (r == 0) {
        func_003191C8(0, &r);
    }
    func_003190E0(p, 30, 2);
    func_00319128(p, 1);
    func_00319178(p, 0);
}
