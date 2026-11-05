struct Set_002639A0 {
    int m0;
    unsigned int m_bits[7];
};

struct Obj_002639A0 {
    Set_002639A0 m_a[21];
    Set_002639A0 m_b[21];
    char pad[0x544 - 0x540];
    unsigned int m_curA[8];
    unsigned int m_curB[8];
    char pad2[0x5C4 - 0x584];
    int m_set;
    void Clear(int bit, int set);
};

void Obj_002639A0::Clear(int bit, int set)
{
    if (set == -1)
        set = m_set;
    unsigned int mask = ~(1 << (bit & 0x1F));
    m_a[set].m_bits[bit >> 5] &= mask;
    m_curA[bit >> 5] &= mask;
}
