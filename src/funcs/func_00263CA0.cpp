struct Set_00263CA0 {
    int m0;
    unsigned int m_bits[7];
};

struct Obj_00263CA0 {
    Set_00263CA0 m_a[21];
    Set_00263CA0 m_b[21];
    char pad[0x544 - 0x540];
    unsigned int m_curA[8];
    unsigned int m_curB[8];
    char pad2[0x5C4 - 0x584];
    int m_set;
    void Set(int bit, int set);
};

void Obj_00263CA0::Set(int bit, int set)
{
    if (set == -1)
        set = m_set;
    m_b[set].m_bits[bit >> 5] |= 1 << (bit & 0x1F);
}
