struct Entry_002668B0 {
    int m_key;
    void* m_value;
    Entry_002668B0* m_next;
};

struct HashTable_002668B0 {
    int m_bits;
    Entry_002668B0* m_table;
    void ForEach(void (*fn)(void*, void*), void* data);
};

void HashTable_002668B0::ForEach(void (*fn)(void*, void*), void* data)
{
    unsigned int size = 1 << m_bits;
    Entry_002668B0* bucket = m_table;
    for (unsigned int i = 0; i < size; i++) {
        Entry_002668B0* e = bucket->m_next;
        while (e) {
            Entry_002668B0* next = e->m_next;
            if (e->m_value)
                fn(e->m_value, data);
            e = next;
        }
        if (bucket->m_value)
            fn(bucket->m_value, data);
        bucket++;
    }
}
