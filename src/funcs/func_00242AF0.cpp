struct Script_00242AF0 {
    char pad[0x18];
    void* m_params;
};

extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_0023F220(void* owner, int id);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

bool Cmd_00242AF0(void* params, Script_00242AF0* script)
{
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    int v = func_0023F220(func_00240850(), id);
    if (v != -1) {
        func_001E7200(script->m_params, 0xCB9D1224, v);
        return true;
    }
    return false;
}
