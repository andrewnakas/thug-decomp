struct Set_00263A40 {
    int m0;
    unsigned int m_bits[7];
};

struct Obj_00263A40 {
    Set_00263A40 m_a[21];
    Set_00263A40 m_b[21];
    char pad[0x544 - 0x540];
    unsigned int m_curA[8];
    unsigned int m_curB[8];
    char pad2[0x5C4 - 0x584];
    int m_set;
    bool Changed(int bit);
};

bool Obj_00263A40::Changed(int bit)
{
    int w = bit >> 5;
    if ((m_a[m_set].m_bits[w] ^ m_curA[w]) & (1 << (bit & 0x1F)))
        return true;
    return false;
}
