struct Entry_00109CC0 {
    int m_key;
    void* m_value;
    Entry_00109CC0* m_next;
};

struct HashTable_00109CC0 {
    int m_bits;
    Entry_00109CC0* m_table;
    void ForEach(void (*fn)(void*, void*), void* data);
};

void HashTable_00109CC0::ForEach(void (*fn)(void*, void*), void* data)
{
    unsigned int size = 1 << m_bits;
    Entry_00109CC0* bucket = m_table;
    for (unsigned int i = 0; i < size; i++) {
        Entry_00109CC0* e = bucket->m_next;
        while (e) {
            Entry_00109CC0* next = e->m_next;
            if (e->m_value)
                fn(e->m_value, data);
            e = next;
        }
        if (bucket->m_value)
            fn(bucket->m_value, data);
        bucket++;
    }
}
