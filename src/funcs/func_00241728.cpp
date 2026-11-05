struct Script_00241728 {
    char pad[0x18];
    void* m_params;
};

extern "C" void* func_00240850();
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_0023D690(void* owner, int flag);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

bool Cmd_00241728(void* params, Script_00241728* script)
{
    void* owner = func_00240850();
    int flag = func_001E8708(params, 0x3DD01EA1);
    void* dst = script->m_params;
    func_001E7200(dst, 0xF9461A46, func_0023D690(owner, flag));
    return true;
}
