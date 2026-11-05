struct Set_00263D80 {
    int m0;
    unsigned int m_bits[7];
};

struct Obj_00263D80 {
    Set_00263D80 m_a[21];
    Set_00263D80 m_b[21];
    char pad[0x544 - 0x540];
    unsigned int m_curA[8];
    unsigned int m_curB[8];
    char pad2[0x5C4 - 0x584];
    int m_set;
    bool Changed(int bit);
};

bool Obj_00263D80::Changed(int bit)
{
    int w = bit >> 5;
    if ((m_b[m_set].m_bits[w] ^ m_curB[w]) & (1 << (bit & 0x1F)))
        return true;
    return false;
}
