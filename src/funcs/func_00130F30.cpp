struct Entry_00130F30 {
    unsigned int m_key;
    void* m_value;
    Entry_00130F30* m_next;
};

extern "C" void func_0010D428(int pool, void* p);

struct HashTable_00130F30 {
    int m_bits;
    Entry_00130F30* m_table;
    int m_count;
    void Remove(const unsigned int* key);
};

void HashTable_00130F30::Remove(const unsigned int* key)
{
    if (!m_table)
        return;
    Entry_00130F30* e = &m_table[*key & ((1 << m_bits) - 1)];
    Entry_00130F30* prev = 0;
    while (e) {
        Entry_00130F30* next = e->m_next;
        if (e->m_key == *key && e->m_value) {
            if (prev) {
                prev->m_next = next;
                func_0010D428(0, e);
            } else {
                e->m_key = 0;
                e->m_value = 0;
            }
            m_count--;
            return;
        }
        prev = e;
        e = next;
    }
}
