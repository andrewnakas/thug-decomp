extern "C" void func_001E70C0(void* a, int b, int d);
extern "C" void func_001E7180(void* a, int b, int d);

extern "C" void func_001E7A30(void* a, int b, int c, int d)
{
    if (c == 3) func_001E70C0(a, b, d);
    else func_001E7180(a, b, d);
}
