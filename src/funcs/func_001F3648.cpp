struct Entry_001F3648 {
    unsigned int m_key;
    void* m_value;
    Entry_001F3648* m_next;
};

struct HashTable_001F3648 {
    int m_bits;
    Entry_001F3648* m_table;
    void* Find(const unsigned int* key);
};

void* HashTable_001F3648::Find(const unsigned int* key)
{
    Entry_001F3648* e = &m_table[(*key & ((1 << m_bits) - 1))];
    while (e) {
        if (e->m_key == *key && e->m_value)
            return e->m_value;
        e = e->m_next;
    }
    return 0;
}
