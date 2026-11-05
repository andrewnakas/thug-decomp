extern char D_00377330[];
extern char D_00453068[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" unsigned int func_001F0D78(char* s);

extern "C" unsigned int func_00292E88(int unused, int n)
{
    func_003331D0(D_00453068, D_00377330, n);
    return func_001F0D78(D_00453068);
}
