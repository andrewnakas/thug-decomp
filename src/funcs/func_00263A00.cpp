struct C_00263A00 {
    int m0;
    unsigned int m4[22][8];
    char m_pad[0x5C4 - 4 - 22 * 32];
    int m5C4;
    bool Test(int bit, int idx);
};

bool C_00263A00::Test(int bit, int idx)
{
    if (idx == -1) idx = m5C4;
    if (m4[idx][bit >> 5] & (1 << (bit & 0x1F))) return true;
    return false;
}
