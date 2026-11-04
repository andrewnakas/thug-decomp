struct Settings_00212810 {
    int m_pad[6];
    int m_enabled;
};

extern Settings_00212810* D_00389044;
extern char D_0038F4F0[];
extern "C" int func_001E87B8(void* params, char* name);

bool Cmd_00212810(void* params, void* script)
{
    D_00389044->m_enabled = func_001E87B8(params, D_0038F4F0) != 0;
    return true;
}
