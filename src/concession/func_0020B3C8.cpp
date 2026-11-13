/* force: {"kind": "sched", "pass": 2, "block": 4, "clock": 1, "first": [93, 184]} */
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7C80(void* params, unsigned int name, const char** out, int req);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" int func_00331BB8(const char* s);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern char D_0038F340[];

struct Script_0020B3C8 {
    char pad[0x18];
    void* m_params;
};

bool Cmd_0020B3C8(void* params, Script_0020B3C8* script)
{
    unsigned int name = 0;
    if (!func_001E8398(params, 0, &name, 0))
        return false;
    const char* str = D_0038F340;
    if (!func_001E7C80(script->m_params, name, &str, 0))
        return false;
    int value = 0;
    func_001E6B90(script->m_params, name);
    int len = func_00331BB8(str);
    for (int i = 0; i < len; i++)
        value = value * 10 + str[i] - '0';
    func_001E7200(script->m_params, name, value);
    return true;
}
