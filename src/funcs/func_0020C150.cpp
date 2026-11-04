struct Script_0020C150 {
    int m_pad[6];
    void* m_params;
};

extern "C" void func_001E6AC8(void* params, void* args);

bool Cmd_0020C150(void* args, Script_0020C150* script)
{
    func_001E6AC8(script->m_params, args);
    return true;
}
