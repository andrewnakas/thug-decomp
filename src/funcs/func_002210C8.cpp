struct Script_002210C8 {
    char pad[0x18];
    void* m_params;
};

extern void* D_0038FC78;
extern "C" void* func_0022E050(void* self);
extern "C" void* func_002629B8(void* obj, unsigned int name);
extern "C" char* func_002624F0(void* obj);
extern "C" void func_001E70C0(void* params, unsigned int name, char* value);

bool Cmd_002210C8(void* params, Script_002210C8* script)
{
    func_001E70C0(script->m_params, 0x2AB66CB8, func_002624F0(func_002629B8(func_0022E050(D_0038FC78), 0xA7BE964)));
    return true;
}
