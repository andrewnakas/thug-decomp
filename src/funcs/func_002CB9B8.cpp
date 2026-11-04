extern "C" int func_001E7DE8(void* p, int key, int* out, int v);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void* func_002C0368();
extern "C" char* func_002BD288(void* p);
extern char D_00392860[];
extern char D_0037ADA8[];

struct Script_002CB9B8 {
    char pad0[0x18];
    void* m18;
};

bool Cmd_002CB9B8(void* params, Script_002CB9B8* script)
{
    int len = -1;
    func_001E7DE8(params, 0, &len, 0);
    char* p = func_002BD288(func_002C0368());
    if (len == -1) {
        if (p)
            func_001E7138(script->m18, D_00392860, p);
        else
            func_001E7138(script->m18, D_00392860, D_0037ADA8);
    } else {
        char buf[64];
        for (int i = 0; i < len; i++)
            buf[i] = p[i];
        buf[len] = 0;
        func_001E7138(script->m18, D_00392860, buf);
    }
    return true;
}
