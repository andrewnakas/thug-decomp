extern "C" void func_0010FE68();
extern "C" int func_001DFD90();
extern "C" const char* func_00106818();
extern "C" int func_003331D0(char*, const char*, ...);
extern "C" char* func_00331A9C(char*, const char*);
extern "C" int func_00331BB8(const char*);
extern "C" char* func_00331678(char*, const char*);
extern "C" int func_00320138(const char*, int, int);

struct Path18_00106B98 {
    char c[18];
};

extern char D_003954E8[];
extern char D_0035AE00[];
extern Path18_00106B98 D_0035AE10;
extern char D_00388950[];
extern int D_0038881C;

int func_00106B98(const char* name, int mode, int arg)
{
    char buf[0x80];
    func_0010FE68();
    if (func_001DFD90())
        return -1;
    if (D_0038881C) {
        func_003331D0(buf, D_0035AE00, func_00106818());
        func_00331A9C(D_003954E8, buf);
    } else {
        *(Path18_00106B98*)D_003954E8 = D_0035AE10;
    }
    char* end = D_003954E8 + func_00331BB8(D_003954E8);
    const char* p = name;
    while (*p) {
        char c = *p++;
        if (c >= 'a' && c <= 'z')
            c -= 32;
        *end++ = c;
    }
    *end = 0;
    func_00331678(D_003954E8, D_00388950);
    int r = func_00320138(D_003954E8, mode, arg);
    if (r >= 0)
        r = 0;
    return r;
}
