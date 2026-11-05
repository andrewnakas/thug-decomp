struct Buf_0010D0E8 {
    int m0;
    int m_pos;
    int m_end;
    Buf_0010D0E8* Advance(int n);
};

Buf_0010D0E8* Buf_0010D0E8::Advance(int n)
{
    m_pos += n;
    if (m_end < m_pos)
        m_end = m_pos;
    return this;
}
