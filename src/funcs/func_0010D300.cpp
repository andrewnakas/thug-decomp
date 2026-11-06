struct Pool_0010D300 {
    char pad0[0x10];
    int m_used;
    void** m_free;
    char pad18[0x58 - 0x18];
    int m_peak;
    void* Alloc();
};

void* Pool_0010D300::Alloc()
{
    if (m_free) {
        m_used++;
        if (m_peak < m_used) m_peak = m_used;
        void** p = m_free;
        m_free = (void**)*p;
        return p;
    }
    return 0;
}
