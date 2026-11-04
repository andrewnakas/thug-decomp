struct Script_00210960 {
    int m_pad[6];
    void* m_params;
};

extern "C" void func_00210458(void* params, void* args);

bool Cmd_00210960(void* args, Script_00210960* script)
{
    func_00210458(script->m_params, args);
    return true;
}
