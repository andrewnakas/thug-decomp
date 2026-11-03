struct Entry_001414D0 {
    unsigned int m_key;
    void* m_value;
    Entry_001414D0* m_next;
};

struct HashTable_001414D0 {
    int m_bits;
    Entry_001414D0* m_table;
    void* Find(const unsigned int* key);
};

void* HashTable_001414D0::Find(const unsigned int* key)
{
    Entry_001414D0* e = &m_table[(*key & ((1 << m_bits) - 1))];
    while (e) {
        if (e->m_key == *key && e->m_value)
            return e->m_value;
        e = e->m_next;
    }
    return 0;
}
