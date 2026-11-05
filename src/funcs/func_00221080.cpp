struct Script_00221080 {
    char pad[0x18];
    void* m_params;
};

extern void* D_0038FC78;
extern "C" void* func_0022E050(void* self);
extern "C" int func_002628F0(void* obj);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

bool Cmd_00221080(void* params, Script_00221080* script)
{
    func_001E7200(script->m_params, 0x3C64476B, func_002628F0(func_0022E050(D_0038FC78)));
    return true;
}
