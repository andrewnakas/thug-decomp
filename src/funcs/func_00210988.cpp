extern char D_003703E8[];
extern char D_00370400[];
extern char D_00370410[];
extern char D_0038F340[];
extern char D_0038F440[];
extern char D_0038F448[];

extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E7D18(void* params, const char* name, const char** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int value);
extern "C" void func_001E6AC8(void* s, void* params);
extern "C" bool func_00210458(void* s, void* p);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" int func_003331D0(char* out, const char* fmt, ...);

extern "C" bool func_00210988(char* out, void* params)
{
    const char* str = D_003703E8;
    if (func_001E8870(params, 0, &str, 0)) {
        void* s = func_001E6978(func_001190D0(8));
        unsigned int a = func_001F0D78(D_00370400);
        func_001E7360(s, a, func_001F0D78(D_00370410));
        func_001E6AC8(s, params);
        if (func_00210458(s, s))
            func_001E7D18(s, D_00370410, &str, 0);
        else
            str = D_0038F340;
        func_003331D0(out, D_0038F440, str);
        if (s)
            func_001E6AE8(s, 3);
        return true;
    }
    int v = 0;
    if (func_001E7DE8(params, 0, &v, 0))
        func_003331D0(out, D_0038F448, v);
    return true;
}
