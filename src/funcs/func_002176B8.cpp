struct Script_002176B8 {
    char pad[0x18];
    void* m_params;
};
extern "C" void* func_0022BFE0(void* params);
extern "C" Script_002176B8* func_0022BEE0(void* p);
extern "C" void func_001E7360(void* dst, unsigned int name, void* src);

extern "C" bool func_002176B8(void* params, Script_002176B8* script)
{
    void* p = func_0022BFE0(params);
    if (p) {
        Script_002176B8* o = func_0022BEE0(p);
        func_001E7360(script->m_params, 0x0830ECAF, o->m_params);
        func_001E7360(script->m_params, 0x52280066, o->m_params);
    }
    return true;
}
