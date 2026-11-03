struct Entry_00109F28 {
    int m_key;
    void* m_value;
    Entry_00109F28* m_next;
};

extern "C" void func_0010D428(int pool, void* p);
extern "C" void func_00109E48(Entry_00109F28* e);

struct HashTable_00109F28 {
    int m_bits;
    Entry_00109F28* m_table;
    int m_count;
    void Clear();
};

void HashTable_00109F28::Clear()
{
    if (!m_table)
        return;
    unsigned int size = 1 << m_bits;
    Entry_00109F28* bucket = m_table;
    for (unsigned int i = 0; i < size; i++) {
        Entry_00109F28* e = bucket->m_next;
        while (e) {
            Entry_00109F28* next = e->m_next;
            func_0010D428(0, e);
            e = next;
        }
        func_00109E48(bucket);
        bucket++;
    }
    m_count = 0;
}
