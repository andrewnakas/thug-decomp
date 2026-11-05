extern char D_003F5380[];
extern "C" void func_001E4ED8(void* p);

extern "C" void func_0021B1A0(int a, int b)
{
    if (b == 0xFFFF && a) {
        func_001E4ED8(D_003F5380);
    }
}
