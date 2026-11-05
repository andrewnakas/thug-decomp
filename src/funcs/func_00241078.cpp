struct Script_00241078 {
    char pad[0x18];
    void* m_params;
};

extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_0023D130(void* owner, int id);
extern "C" void func_001E6AC8(void* dst, void* src);

bool Cmd_00241078(void* params, Script_00241078* script)
{
    void* owner = func_00240850();
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    void* dst = script->m_params;
    func_001E6AC8(dst, func_0023D130(owner, id));
    return true;
}
