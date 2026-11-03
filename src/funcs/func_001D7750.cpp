struct Obj_001D7750 {
    int m_bits;
    void Set(int v);
};

void Obj_001D7750::Set(int v)
{
    m_bits = (m_bits & ~3) | (v & 3);
}
