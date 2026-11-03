struct Entry_00266790 {
    int m_key;
    void* m_value;
    Entry_00266790* m_next;
};

extern "C" void func_0010D428(int pool, void* p);
extern "C" void func_002666B0(Entry_00266790* e);

struct HashTable_00266790 {
    int m_bits;
    Entry_00266790* m_table;
    int m_count;
    void Clear();
};

void HashTable_00266790::Clear()
{
    if (!m_table)
        return;
    unsigned int size = 1 << m_bits;
    Entry_00266790* bucket = m_table;
    for (unsigned int i = 0; i < size; i++) {
        Entry_00266790* e = bucket->m_next;
        while (e) {
            Entry_00266790* next = e->m_next;
            func_0010D428(0, e);
            e = next;
        }
        func_002666B0(bucket);
        bucket++;
    }
    m_count = 0;
}
