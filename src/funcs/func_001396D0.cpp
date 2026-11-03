struct Entry_001396D0 {
    int m_key;
    void* m_value;
    Entry_001396D0* m_next;
};

extern "C" void func_0010D428(int pool, void* p);
extern "C" void func_001395F0(Entry_001396D0* e);

struct HashTable_001396D0 {
    int m_bits;
    Entry_001396D0* m_table;
    int m_count;
    void Clear();
};

void HashTable_001396D0::Clear()
{
    if (!m_table)
        return;
    unsigned int size = 1 << m_bits;
    Entry_001396D0* bucket = m_table;
    for (unsigned int i = 0; i < size; i++) {
        Entry_001396D0* e = bucket->m_next;
        while (e) {
            Entry_001396D0* next = e->m_next;
            func_0010D428(0, e);
            e = next;
        }
        func_001395F0(bucket);
        bucket++;
    }
    m_count = 0;
}
