struct Script_002418D0 {
    char pad0[0x18];
    void* m_params;
};

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_00240850();
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" int func_0023DD78(void* game, int id, bool flag);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

bool func_002418D0(void* params, Script_002418D0* script)
{
    int id;
    func_001E7DE8(params, 0, &id, 1);
    func_001E7200(script->m_params, 0x8110DCDF, func_0023DD78(func_00240850(), id, func_001E8708(params, 0x8690A9CF)));
    return true;
}
