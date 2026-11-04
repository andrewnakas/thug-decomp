extern char D_00394380[];
extern char D_00388578[];
extern int D_0038880C;
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00331BB8(const char* s);

extern "C" char* func_001044A8(int n)
{
    char* p = D_00394380;
    if (n < 0) {
        *p++ = '-';
        n = -n;
    }
    char buf[32];
    func_003331D0(buf, D_00388578, n);
    int len = func_00331BB8(buf);
    char* s = buf;
    char sep;
    switch (D_0038880C) {
    case 3:
        sep = ' ';
        break;
    case 4:
        sep = '.';
        break;
    case 5:
        sep = '.';
        break;
    case 6:
        sep = '.';
        break;
    default:
        sep = ',';
        break;
    }
    while (len != 0) {
        *p++ = *s++;
        len--;
        if (len != 0 && len % 3 == 0) {
            *p++ = sep;
        }
    }
    *p = 0;
    return D_00394380;
}
