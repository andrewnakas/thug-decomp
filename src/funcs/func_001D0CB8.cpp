struct Entry_001D0CB8 {
    int m_key;
    void* m_value;
    Entry_001D0CB8* m_next;
};

extern "C" void func_0010D428(int pool, void* p);
extern "C" void func_001D0BD8(Entry_001D0CB8* e);

struct HashTable_001D0CB8 {
    int m_bits;
    Entry_001D0CB8* m_table;
    int m_count;
    void Clear();
};

void HashTable_001D0CB8::Clear()
{
    if (!m_table)
        return;
    unsigned int size = 1 << m_bits;
    Entry_001D0CB8* bucket = m_table;
    for (unsigned int i = 0; i < size; i++) {
        Entry_001D0CB8* e = bucket->m_next;
        while (e) {
            Entry_001D0CB8* next = e->m_next;
            func_0010D428(0, e);
            e = next;
        }
        func_001D0BD8(bucket);
        bucket++;
    }
    m_count = 0;
}
