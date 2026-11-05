struct Entry_0011D798 {
    int m_key;
    int m4[11];
};

struct Table_0011D798 {
    int m0[5];
    int m_count;
    Entry_0011D798* m_entries;
    int IndexOf(int key);
};

int Table_0011D798::IndexOf(int key)
{
    for (int i = 0; i < m_count; i++) {
        if (key == m_entries[i].m_key)
            return i;
    }
    return -1;
}
