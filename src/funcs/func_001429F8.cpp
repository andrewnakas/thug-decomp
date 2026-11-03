struct Entry_001429F8 {
    int m_key;
    void* m_value;
    Entry_001429F8* m_next;
};

extern "C" void func_0010D428(int pool, void* p);
extern "C" void func_00142918(Entry_001429F8* e);

struct HashTable_001429F8 {
    int m_bits;
    Entry_001429F8* m_table;
    int m_count;
    void Clear();
};

void HashTable_001429F8::Clear()
{
    if (!m_table)
        return;
    unsigned int size = 1 << m_bits;
    Entry_001429F8* bucket = m_table;
    for (unsigned int i = 0; i < size; i++) {
        Entry_001429F8* e = bucket->m_next;
        while (e) {
            Entry_001429F8* next = e->m_next;
            func_0010D428(0, e);
            e = next;
        }
        func_00142918(bucket);
        bucket++;
    }
    m_count = 0;
}
