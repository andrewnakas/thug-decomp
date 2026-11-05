struct Script_00242CF8 {
    char pad[0x18];
    void* m_params;
};

extern "C" void* func_00240850();
extern "C" void* func_0023F308(void* owner);
extern "C" void func_001E78A8(void* params, unsigned int name, void* value);

bool Cmd_00242CF8(void* params, Script_00242CF8* script)
{
    void* owner = func_00240850();
    void* dst = script->m_params;
    func_001E78A8(dst, 0xD23AD129, func_0023F308(owner));
    return true;
}
