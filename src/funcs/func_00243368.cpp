struct Script_00243368 {
    char pad[0x18];
    void* m_params;
};

extern "C" void* func_00240850();
extern "C" int func_00240120(void* owner, int flag);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

bool Cmd_00243368(void* params, Script_00243368* script)
{
    func_001E7200(script->m_params, 0x3671F748, func_00240120(func_00240850(), 0));
    return true;
}
