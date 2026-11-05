struct Owner_002432D0 {
    char pad[0x58];
    unsigned int m_58;
};

extern "C" Owner_002432D0* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);

bool Cmd_002432D0(void* params, void* script)
{
    Owner_002432D0* owner = func_00240850();
    unsigned int v;
    func_001E8398(params, 0x63B1214E, &v, 1);
    owner->m_58 = v;
    return true;
}
