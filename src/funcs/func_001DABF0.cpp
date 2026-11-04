struct Entry_001DABF0 {
    int m_key;
    int m_value;
};

struct Table_001DABF0 {
    char m_pad[0x20];
    Entry_001DABF0 m_entries[500];
    int m_count;
    int m_active;
    void Remove(int key);
};

void Table_001DABF0::Remove(int key)
{
    for (int i = 0; i < m_active; i++) {
        if (m_entries[i].m_key == key) {
            for (int j = i + 1; j < m_count; j++) {
                m_entries[j - 1] = m_entries[j];
            }
            m_active--;
            m_count--;
            return;
        }
    }
}
