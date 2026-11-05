struct Entry_0011D4F0 {
    int m_key;
    int m4[11];
};

struct Table_0011D4F0 {
    int m0[5];
    int m_count;
    Entry_0011D4F0* m_entries;
    Entry_0011D4F0* Find(int key);
};

Entry_0011D4F0* Table_0011D4F0::Find(int key)
{
    for (int i = 0; i < m_count; i++) {
        if (key == m_entries[i].m_key)
            return &m_entries[i];
    }
    return 0;
}
