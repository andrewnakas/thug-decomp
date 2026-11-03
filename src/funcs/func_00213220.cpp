struct Settings_00213220 {
    int m_pad[5];
    int m_flag;
};

extern Settings_00213220* D_00389044;

bool Cmd_00213220(void* params, void* script)
{
    D_00389044->m_flag ^= 1;
    return true;
}
