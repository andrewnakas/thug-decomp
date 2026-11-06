struct Name_00214740 {
    int m_v;
    Name_00214740() : m_v(0) {}
};

struct Script_00214740 {
    char m_pad0[0xBC];
    void* m_obj;
};

extern char D_0038F580[];
extern char D_0038F588[];

extern "C" bool func_00214600(void* params, Script_00214740* script);
extern "C" bool func_001E8398(void* params, int name, int* out, int required);
extern "C" int func_001F0CD0(Script_00214740* script);
extern "C" bool func_001E84E8(void* params, char* name, int* out, int required);
extern "C" bool func_001E81F0(void* params, char* name, int* out, int required);
extern "C" void func_00184B30(void* obj, int a, int b, int c, int d);

bool Cmd_00214740(void* params, Script_00214740* script)
{
    if (!script->m_obj)
        return func_00214600(params, script);
    int v;
    if (func_001E8398(params, 0, &v, 0)) {
        /* the game stores 0 to a's stack slot before the call result (&a escapes): both stores are real */
        int a = 0;
        a = func_001F0CD0(script);
        func_001E84E8(params, D_0038F580, &a, 0);
        int b = 0;
        func_001E81F0(params, D_0038F588, &b, 0);
        func_00184B30(script->m_obj, v, b, a, 0);
    }
    return true;
}
