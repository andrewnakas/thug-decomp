typedef char* va_list_00103F28;

extern "C" int func_00334070(char* buf, const char* fmt, va_list_00103F28 ap);
extern "C" int func_00346230(const char* s);
extern "C" void func_0020AF20(const char* s);
extern "C" int func_00332FB0(const char* fmt, ...);
extern int D_00388814;
extern int D_0038F32C;
extern char D_00388548[];

extern "C" int func_00103F28(const char* fmt, ...)
{
    char buf[1024];
    int ret = -1;
    va_list_00103F28 ap;
    buf[0] = 0;
    ap = (va_list_00103F28)__builtin_next_arg(fmt) - (8 - __builtin_args_info(2)) * 8;
    func_00334070(buf, fmt, ap);
    switch (D_00388814) {
    case 2:
        ret = func_00346230(buf);
        break;
    case 1:
    case 3:
        if (D_0038F32C == 1) {
            func_0020AF20(buf);
        }
        func_00332FB0(D_00388548, buf);
        break;
    }
    return ret;
}
