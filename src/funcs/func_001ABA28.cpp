extern "C" unsigned int func_0010FC30();

struct Entry_001ABA28 {
    unsigned int m_time;
    int m_kind;
    unsigned int m_name;
    int mC;
    int m_used;
    unsigned int m_flags;
};

struct C_001ABA28 {
    int m_pad[15];
    Entry_001ABA28 m_entries[100];
    unsigned short m_count;
    unsigned short m_last;
    void Expire(unsigned int name, unsigned int maxAge);
};

void C_001ABA28::Expire(unsigned int name, unsigned int maxAge)
{
    int idx = m_last;
    for (int i = 0; i < m_count; i++) {
        if (m_entries[idx].m_name == name) {
            unsigned int t = m_entries[idx].m_time;
            if (func_0010FC30() - t >= maxAge) m_entries[idx].m_flags = 0xFFFFFFFF;
        }
        idx--;
        if (idx < 0) idx += 100;
    }
}
