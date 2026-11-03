struct Entry_0018AD18 {
    int m_key;
    void* m_value;
    Entry_0018AD18* m_next;
};

extern "C" void func_0010D428(int pool, void* p);
extern "C" void func_0018A9E0(Entry_0018AD18* e);

struct HashTable_0018AD18 {
    int m_bits;
    Entry_0018AD18* m_table;
    int m_count;
    void Clear();
};

void HashTable_0018AD18::Clear()
{
    if (!m_table)
        return;
    unsigned int size = 1 << m_bits;
    Entry_0018AD18* bucket = m_table;
    for (unsigned int i = 0; i < size; i++) {
        Entry_0018AD18* e = bucket->m_next;
        while (e) {
            Entry_0018AD18* next = e->m_next;
            func_0010D428(0, e);
            e = next;
        }
        func_0018A9E0(bucket);
        bucket++;
    }
    m_count = 0;
}
