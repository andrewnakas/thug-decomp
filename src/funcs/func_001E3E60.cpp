extern int D_0038881C;
extern char D_003F2BD0[];
extern "C" bool func_001E53A0(unsigned int name, int a);
extern "C" int func_001E3F08(void* list, void* p, int flag, int b);

extern "C" int func_001E3E60(void* p)
{
    int flag = 0;
    if (!D_0038881C) {
        if (!func_001E53A0(0x62DF9442, 0))
            return 0;
        flag = 1;
    }
    return func_001E3F08(D_003F2BD0, p, flag, 0);
}
