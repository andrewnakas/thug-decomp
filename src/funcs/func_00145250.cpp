struct Entry_00145250 {
    int m_key;
    void* m_value;
    Entry_00145250* m_next;
};

extern "C" void func_0010D428(int pool, void* p);
extern "C" void func_00145170(Entry_00145250* e);

struct HashTable_00145250 {
    int m_bits;
    Entry_00145250* m_table;
    int m_count;
    void Clear();
};

void HashTable_00145250::Clear()
{
    if (!m_table)
        return;
    unsigned int size = 1 << m_bits;
    Entry_00145250* bucket = m_table;
    for (unsigned int i = 0; i < size; i++) {
        Entry_00145250* e = bucket->m_next;
        while (e) {
            Entry_00145250* next = e->m_next;
            func_0010D428(0, e);
            e = next;
        }
        func_00145170(bucket);
        bucket++;
    }
    m_count = 0;
}
