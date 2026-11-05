struct Bits_001FAB88 {
    unsigned int* m_ptr;
    int m_4;
    unsigned int m_bits;
    int m_avail;
    int m_10;
    int m_total;

    int Read(int n);
};

int Bits_001FAB88::Read(int n)
{
    m_total += n;
    if (m_avail == 0) {
        m_bits = *m_ptr;
        m_ptr++;
        m_avail = 32;
    }
    unsigned long v;
    if (n <= m_avail) {
        m_avail = m_avail - n;
        if (n == 32) {
            v = m_bits;
        } else {
            v = m_bits & ((1 << n) - 1);
        }
        m_bits >>= n;
    } else {
        n -= m_avail;
        unsigned int w = *m_ptr;
        v = (unsigned int)((m_bits & ((1 << m_avail) - 1)) | ((w & ((1 << n) - 1)) << m_avail));
        m_ptr++;
        m_bits = w >> n;
        m_avail = 32 - n;
    }
    return v;
}
