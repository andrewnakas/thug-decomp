extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" unsigned int func_001EC7A0(unsigned char* p);

struct Script_001EF140 {
    char pad0[0x10];
    unsigned char* m_pc;
    char pad14[0x4];
    void* m_params;

    unsigned int ReadChecksum();
};

unsigned int Script_001EF140::ReadChecksum()
{
    unsigned int v = 0;
    switch (*m_pc) {
    case 0x2C:
        m_pc++;
        func_001E8398(m_params, 0, &v, 0);
        break;
    case 0x2D:
        {
            m_pc += 2;
            unsigned int name = func_001EC7A0(m_pc);
            m_pc += 4;
            func_001E8398(m_params, name, &v, 0);
        }
        break;
    case 0x16:
        m_pc++;
        v = func_001EC7A0(m_pc);
        m_pc += 4;
        break;
    }
    return v;
}
