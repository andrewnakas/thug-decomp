extern char D_00370768[];
extern char D_00370778[];
extern char D_00370788[];
extern char D_003F5360[];

struct Script_00212CC8 {
    char pad[0x18];
    void* m_params;
};

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E84E8(void* params, const char* name, int* out, int required);
extern "C" void* func_002304D0(int type, int a);
extern "C" void* func_00202EF8(void* p, unsigned int name);
extern "C" bool func_001E7D18(void* p, const char* name, const char** out, int required);
extern "C" unsigned int func_00331BB8(const char* s);
extern "C" void func_001E7138(void* params, const char* name, const char* value);

bool Cmd_00212CC8(void* params, Script_00212CC8* script)
{
    unsigned int i = 0;
    void* out = script->m_params;
    unsigned int name;
    func_001E8398(params, 0, &name, 0);
    int type;
    func_001E84E8(params, D_00370768, &type, 0);
    const char* str;
    func_001E7D18(func_00202EF8(func_002304D0(type, 1), name), D_00370778, &str, 0);
    for (; i < func_00331BB8(str); i++)
        D_003F5360[i] = '*';
    D_003F5360[i] = 0;
    func_001E7138(out, D_00370788, D_003F5360);
    return true;
}
