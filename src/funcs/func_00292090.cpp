extern char D_003772C8[];
extern char D_003772E0[];
extern char D_00377300[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" unsigned int func_001F0D78(char* s);

extern "C" unsigned int func_00292090(int a, int n)
{
    char buf[0x70];
    buf[0] = 0;
    switch (n) {
    case 0:
        func_003331D0(buf, D_003772C8, a);
        break;
    case 1:
        func_003331D0(buf, D_003772E0, a);
        break;
    default:
        func_003331D0(buf, D_00377300, a, n - 2);
        break;
    }
    return func_001F0D78(buf);
}
