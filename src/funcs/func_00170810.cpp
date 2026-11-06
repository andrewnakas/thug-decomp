struct Obj_00170810 {
    int m0[7];
    unsigned int m_flags;
    int m_20;
    int m_24;
    int m28;
    int m_2C;
    void SetTop(unsigned int v);
};

void Obj_00170810::SetTop(unsigned int v)
{
    m_flags = (m_flags & 0xFFFFFF) | (v << 24);
}
