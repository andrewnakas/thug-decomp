struct C_00263C48 {
    char m_pad[0x584];
    unsigned int m584[8];
    void ClearFlag(int bit);
};

void C_00263C48::ClearFlag(int bit)
{
    m584[bit >> 5] &= ~(1 << (bit & 0x1F));
}
