struct Entry_00266978 {
    unsigned int m_key;
    void* m_value;
    Entry_00266978* m_next;
};

struct HashTable_00266978 {
    int m_bits;
    Entry_00266978* m_table;
    void* Find(const unsigned int* key);
};

void* HashTable_00266978::Find(const unsigned int* key)
{
    Entry_00266978* e = &m_table[(*key & ((1 << m_bits) - 1))];
    while (e) {
        if (e->m_key == *key && e->m_value)
            return e->m_value;
        e = e->m_next;
    }
    return 0;
}
