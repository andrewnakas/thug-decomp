struct Script_00241EA0 {
    char pad[0x18];
    void* m_params;
};

extern "C" void* func_00240850();
extern "C" void* func_0023EBD0(void* owner);
extern "C" unsigned int func_00246258(void* item);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);

bool Cmd_00241EA0(void* params, Script_00241EA0* script)
{
    void* item = func_0023EBD0(func_00240850());
    if (item) {
        void* dst = script->m_params;
        func_001E7360(dst, 0x9982E501, func_00246258(item));
        return true;
    }
    return false;
}
