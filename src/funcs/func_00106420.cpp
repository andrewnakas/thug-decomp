extern "C" int func_00331BB8(const char*);
extern "C" char* func_00331A9C(char*, const char*);
extern "C" int func_00336228(const char*, const char*);

bool func_00106420(const char* str, const char* prefix)
{
    char buf[0x70];
    if (!str)
        return false;
    if (!prefix)
        return false;
    int len = func_00331BB8(str);
    int plen = func_00331BB8(prefix);
    if (len < plen)
        return false;
    func_00331A9C(buf, str);
    buf[plen] = 0;
    return func_00336228(buf, prefix) == 0;
}
