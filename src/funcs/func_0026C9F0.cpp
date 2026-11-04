struct Entry_0026C9F0 {
    unsigned int m_key;
    void* m_value;
    Entry_0026C9F0* m_next;
};

extern "C" void* func_0010D3C8(int pool);
extern "C" Entry_0026C9F0* func_0026C7A8(void* mem);

struct HashTable_0026C9F0 {
    int m_bits;
    Entry_0026C9F0* m_table;
    int m_count;
    bool Insert(const unsigned int* key, void* value);
};

bool HashTable_0026C9F0::Insert(const unsigned int* key, void* value)
{
    unsigned int k = *key;
    Entry_0026C9F0* b = &m_table[k & ((1 << m_bits) - 1)];
    if (b->m_value) {
        Entry_0026C9F0* e = func_0026C7A8(func_0010D3C8(0));
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
