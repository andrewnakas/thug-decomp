struct Obj_00263C78 {
    char pad[0x584];
    unsigned int m_bits[8];
    bool Test(int bit);
};

bool Obj_00263C78::Test(int bit)
{
    if (m_bits[bit >> 5] & (1 << (bit & 0x1F)))
        return true;
    return false;
}
