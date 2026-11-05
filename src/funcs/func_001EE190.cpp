extern char D_003F31D8[];
extern char D_003F33D8[];
extern "C" void func_001F12A0(void* p);
extern "C" void func_001E4ED8(void* p);

extern "C" void func_001EE190(int a, int b)
{
    if (b == 0xFFFF && a) {
        func_001F12A0(D_003F31D8);
        func_001E4ED8(D_003F33D8);
    }
}
