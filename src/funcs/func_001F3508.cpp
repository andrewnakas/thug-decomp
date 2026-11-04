struct Entry_001F3508 {
    int m_key;
    void* m_value;
    Entry_001F3508* m_next;
};

extern "C" void func_0010D428(int pool, void* p);
extern "C" void func_001F32B0(Entry_001F3508* e);

struct HashTable_001F3508 {
    int m_bits;
    Entry_001F3508* m_table;
    int m_count;
    void Clear();
};

void HashTable_001F3508::Clear()
{
    if (!m_table)
        return;
    unsigned int size = 1 << m_bits;
    Entry_001F3508* bucket = m_table;
    for (unsigned int i = 0; i < size; i++) {
        Entry_001F3508* e = bucket->m_next;
        while (e) {
            Entry_001F3508* next = e->m_next;
            func_0010D428(0, e);
            e = next;
        }
        func_001F32B0(bucket);
        bucket++;
    }
    m_count = 0;
}
