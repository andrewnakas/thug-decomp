extern "C" unsigned int func_0010FC30();

struct Entry_001ABB20 {
    unsigned int m_time;
    int m_kind;
    unsigned int m_name;
    int mC;
    int m_used;
    int m_flags;
};

struct C_001ABB20 {
    int m_pad[15];
    Entry_001ABB20 m_entries[100];
    unsigned short m_count;
    unsigned short m_last;
    int Find(unsigned int name, unsigned int maxAge, int mask);
};

int C_001ABB20::Find(unsigned int name, unsigned int maxAge, int mask)
{
    int idx = m_last;
    for (int i = 0; i < m_count; i++) {
        unsigned int t = m_entries[idx].m_time;
        if (func_0010FC30() - t >= maxAge) return 0;
        if (!(m_entries[idx].m_flags & mask) && m_entries[idx].m_kind == 1
            && m_entries[idx].m_name == name) {
            m_entries[idx].m_used = 1;
            return 1;
        }
        idx--;
        if (idx < 0) idx += 100;
    }
    return 0;
}
