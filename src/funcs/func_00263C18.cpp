struct Obj_00263C18 {
    char pad[0x584];
    unsigned int m_bits[8];
    void Set(int bit);
};

void Obj_00263C18::Set(int bit)
{
    m_bits[bit >> 5] |= 1 << (bit & 0x1F);
}
