struct Obj_001722B8 {
    int m0[7];
    unsigned int m_flags;
    int m_20;
    int m_24;
    int m28;
    int m_2C;
    void SetFlag(int on);
};

void Obj_001722B8::SetFlag(int on)
{
    m_flags = on ? (m_flags | 0x10000) : (m_flags & ~0x10000);
}
