struct Range_0010D2D0 {
    unsigned int m_lo;
    unsigned int m_hi;
    bool Contains(unsigned int a);
};

bool Range_0010D2D0::Contains(unsigned int a)
{
    if (a >= m_lo && a < m_hi)
        return true;
    return false;
}
