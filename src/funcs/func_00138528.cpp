extern "C" int func_00331BB8(const char* s);
extern "C" int func_00105520(const char* s);

extern "C" int func_00138528(const char* path)
{
    int n = func_00331BB8(path);
    while (n > 0 && path[n - 1] != '\\' && path[n - 1] != '/')
        n--;
    return func_00105520(path + n);
}
