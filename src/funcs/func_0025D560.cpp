extern char D_00452130[];
extern char D_00390C08[];
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" char* func_003364D8(const char* s, const char* sub);

char* Fn_0025D560(const char* path)
{
    for (int i = func_00331BB8(path); i >= 0; i--) {
        if (path[i] == '\\' || path[i] == '/') {
            func_00331A9C(D_00452130, path + (i + 1));
            break;
        }
    }
    char* p = func_003364D8(D_00452130, D_00390C08);
    if (p) *p = 0;
    return D_00452130;
}
