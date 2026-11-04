struct BitWriter_001FAA70 {
    unsigned int* m_ptr;
    int pad4;
    unsigned int m_cur;
    int m_left;
    int pad10;
    int m_total;

    void Flush()
    {
        *m_ptr = m_cur;
        m_left = 32;
        m_cur = 0;
        m_ptr++;
    }
    void Write(int value, int bits);
};

void BitWriter_001FAA70::Write(int value, int bits)
{
    m_total += bits;
    if (m_left < bits) {
        int n = 32 - m_left;
        m_cur = (m_cur & ((1 << n) - 1)) | (value << n);
        bits -= m_left;
        value >>= m_left;
        Flush();
    }
    int n = 32 - m_left;
    m_left -= bits;
    m_cur = (m_cur & ((1 << n) - 1)) | (value << n);
    if (m_left == 0)
        Flush();
}
