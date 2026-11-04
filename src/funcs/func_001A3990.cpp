struct Entry_001A3990 {
    unsigned int m_id;
    int m4[10];
    int m_time;
};

struct C_001A3990 {
    int m_pad[15];
    Entry_001A3990 m_entries[2];
    void Add(const Entry_001A3990* e, int now);
};

void C_001A3990::Add(const Entry_001A3990* e, int now)
{
    for (int i = 0; i < 2; i++) {
        if (!m_entries[i].m_id) {
            m_entries[i] = *e;
            m_entries[i].m_time = now + 2000;
            return;
        }
    }
}
