extern char D_003BD870[];
extern char D_0035C220[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

extern "C" char* func_00114160(signed char* id)
{
    func_003331D0(D_003BD870, D_0035C220, id[4], id[7], id[8], id[9], id[10], id[11]);
    return D_003BD870;
}
