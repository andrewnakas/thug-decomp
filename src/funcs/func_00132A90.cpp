struct Entry_00132A90 {
    int m_key;
    void* m_value;
    Entry_00132A90* m_next;
};

struct HashTable_00132A90 {
    int m_bits;
    Entry_00132A90* m_table;
    int m8;
    int m_bucket;
    Entry_00132A90* m_cur;
    void* Next(int* key);
};

void* HashTable_00132A90::Next(int* key)
{
    int size = 1 << m_bits;
    if (m_cur)
        m_cur = m_cur->m_next;
    else if (m_bucket >= 0)
        return 0;
    if (!m_cur) {
        for (;;) {
            m_bucket++;
            if (m_bucket >= size)
                return 0;
            m_cur = &m_table[m_bucket];
            if (m_cur->m_value)
                break;
            if (m_cur->m_next) {
                m_cur = m_cur->m_next;
                break;
            }
        }
        if (!m_cur)
            return 0;
    }
    if (key)
        *key = m_cur->m_key;
    return m_cur->m_value;
}
