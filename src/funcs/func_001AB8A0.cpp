extern "C" unsigned int func_0010FC30();

struct Entry_001AB8A0 {
    unsigned int m_time;
    int m_kind;
    unsigned int m_name;
    int mC;
    int m_used;
    int m_flags;
};

struct C_001AB8A0 {
    int m_pad[15];
    Entry_001AB8A0 m_entries[100];
    unsigned short m_count;
    unsigned short m_last;
    Entry_001AB8A0* Add(int kind);
};

Entry_001AB8A0* C_001AB8A0::Add(int kind)
{
    m_last++;
    if (m_last >= 100) m_last = 0;
    if (m_count < 100) m_count++;
    m_entries[m_last].m_kind = kind;
    m_entries[m_last].m_time = func_0010FC30();
    m_entries[m_last].m_used = 0;
    m_entries[m_last].m_flags = 0;
    return &m_entries[m_last];
}
