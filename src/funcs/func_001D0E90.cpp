struct Entry_001D0E90 {
    unsigned int m_key;
    void* m_value;
    Entry_001D0E90* m_next;
};

struct HashTable_001D0E90 {
    int m_bits;
    Entry_001D0E90* m_table;
    void* Find(const unsigned int* key);
};

void* HashTable_001D0E90::Find(const unsigned int* key)
{
    Entry_001D0E90* e = &m_table[(*key & ((1 << m_bits) - 1))];
    while (e) {
        if (e->m_key == *key && e->m_value)
            return e->m_value;
        e = e->m_next;
    }
    return 0;
}
