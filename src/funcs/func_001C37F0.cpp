extern "C" int func_0010FC30();

struct Obj_001C37F0 {
    char m_pad0[0xB4];
    int m_B4;
    char m_pad1[0xD0 - 0xB8];
    int m_D0;
    char m_pad2[0x1E0 - 0xD4];
    int m_1E0;
    char m_pad3[0x730 - 0x1E4];
    int m_730;
    char m_pad4[0xA64 - 0x734];
    int m_A64;
    int m_A68;
    bool Check();
};

bool Obj_001C37F0::Check()
{
    if ((!m_D0 && !m_1E0 && !m_730) || !m_B4) {
        m_A64 = 0;
        return false;
    }
    if (!m_A64) {
        m_A68 = func_0010FC30();
        m_A64 = 1;
    }
    return true;
}
