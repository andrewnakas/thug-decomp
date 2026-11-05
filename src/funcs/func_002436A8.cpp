struct Owner_002436A8 {
    char pad[0x50];
    unsigned int m_50;
};

extern "C" Owner_002436A8* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);

bool Cmd_002436A8(void* params, void* script)
{
    Owner_002436A8* owner = func_00240850();
    unsigned int v;
    func_001E8398(params, 0, &v, 1);
    owner->m_50 = v;
    return true;
}
