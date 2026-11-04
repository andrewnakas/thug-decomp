struct Entry_00134BB8 {
    unsigned int m_key;
    void* m_value;
    Entry_00134BB8* m_next;
};

struct HashTable_00134BB8 {
    int m_bits;
    Entry_00134BB8* m_table;
    void* Find(const unsigned int* key);
};

void* HashTable_00134BB8::Find(const unsigned int* key)
{
    Entry_00134BB8* e = &m_table[(*key & ((1 << m_bits) - 1))];
    while (e) {
        if (e->m_key == *key && e->m_value)
            return e->m_value;
        e = e->m_next;
    }
    return 0;
}
