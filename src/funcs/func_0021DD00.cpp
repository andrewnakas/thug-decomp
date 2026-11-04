struct Goal_0021DD00 {
    char pad0[0xC];
    int m_count;
    char pad10[8];
    int m_18;
    char pad1C[0x40];
    int m_value;
};

struct Script_0021DD00 {
    char pad0[0x18];
    void* m_params;
};

extern "C" Goal_0021DD00* func_0021B348(void* params);
extern "C" int func_002392B8(Goal_0021DD00* g);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

bool func_0021DD00(void* params, Script_0021DD00* script)
{
    Goal_0021DD00* g = func_0021B348(params);
    func_001E7200(script->m_params, 0x95E84391, g->m_count * g->m_value);
    void* out = script->m_params;
    func_001E7200(out, 0xEE5B2B48, func_002392B8(g));
    func_001E7200(script->m_params, 0xEA60AC69, g->m_18);
    return true;
}
