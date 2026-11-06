extern "C" unsigned int func_0010FC30();

struct Entry_001ABC58 {
    unsigned int m_time;
    int m_type;
    int m_key;
    int mC;
    int m_used;
    int m_flags;
};

struct Obj_001ABC58 {
    char pad0[0x3C];
    Entry_001ABC58 m_entries[100];
    unsigned short m_count;
    unsigned short m_head;
    bool Fn(int a, int b, unsigned int window, int mask);
};

bool Obj_001ABC58::Fn(int a, int b, unsigned int window, int mask)
{
    int idx = m_head;
    bool started = false;
    bool gotA = false;
    bool gotB = false;
    for (int i = 0; i < m_count; i++) {
        unsigned int t = m_entries[idx].m_time;
        if (func_0010FC30() - t >= window)
            return false;
        if (!(m_entries[idx].m_flags & mask) && m_entries[idx].m_type == 1) {
            if (m_entries[idx].m_key == a) {
                m_entries[idx].m_used = 1;
                if (gotB)
                    return true;
                gotA = true;
                started = true;
            } else if (m_entries[idx].m_key == b) {
                m_entries[idx].m_used = 1;
                if (gotA)
                    return true;
                gotB = true;
                started = true;
            } else if (started) {
                return false;
            }
        }
        idx--;
        if (idx < 0)
            idx += 100;
    }
    return false;
}
