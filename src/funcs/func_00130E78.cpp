struct Entry_00130E78 {
    unsigned int m_key;
    void* m_value;
    Entry_00130E78* m_next;
};

extern "C" void* func_0010D3C8(int pool);
extern "C" Entry_00130E78* func_00130E50(void* mem);

struct HashTable_00130E78 {
    int m_bits;
    Entry_00130E78* m_table;
    int m_count;
    bool Insert(const unsigned int* key, void* value);
};

bool HashTable_00130E78::Insert(const unsigned int* key, void* value)
{
    unsigned int k = *key;
    Entry_00130E78* b = &m_table[k & ((1 << m_bits) - 1)];
    if (b->m_value) {
        Entry_00130E78* e = func_00130E50(func_0010D3C8(0));
        e->m_key = *key;
        e->m_value = value;
        e->m_next = b->m_next;
        b->m_next = e;
    } else {
        b->m_key = k;
        b->m_value = value;
    }
    m_count++;
    return true;
}
