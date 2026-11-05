struct Script_00242C58 {
    char pad[0x18];
    void* m_params;
};

extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_0023F2C0(void* owner, int id);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

bool Cmd_00242C58(void* params, Script_00242C58* script)
{
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    func_001E7200(script->m_params, 0xFF61BA23, func_0023F2C0(func_00240850(), id));
    return true;
}
