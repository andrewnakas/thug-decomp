extern char D_003F3170[];
extern char D_00364870[];
extern "C" char* func_001E6178(unsigned int id);
extern "C" int func_003331D0(char* buf, char* fmt, unsigned int id);

extern "C" char* func_001E61F0(unsigned int id)
{
    char* s = func_001E6178(id);
    if (s)
        return s;
    func_003331D0(D_003F3170, D_00364870, id);
    return D_003F3170;
}
