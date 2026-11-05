struct Ring_001F6DC8 {
    char pad[0x50000];
    int m_pos;
    int m_count;
    int m_size;
    void Add(int n);
};

void Ring_001F6DC8::Add(int n)
{
    int room = m_size - m_count;
    if (n < room)
        room = n;
    m_pos = (m_pos + room) % m_size;
    m_count += room;
}
