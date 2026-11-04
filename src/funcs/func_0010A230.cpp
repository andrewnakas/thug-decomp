struct Entry_0010A230 {
    unsigned int m_key;
    void* m_value;
    Entry_0010A230* m_next;
};

struct HashTable_0010A230 {
    int m_bits;
    Entry_0010A230* m_table;
    void* Find(const unsigned int* key);
};

void* HashTable_0010A230::Find(const unsigned int* key)
{
    Entry_0010A230* e = &m_table[(*key & ((1 << m_bits) - 1))];
    while (e) {
        if (e->m_key == *key && e->m_value)
            return e->m_value;
        e = e->m_next;
    }
    return 0;
}
