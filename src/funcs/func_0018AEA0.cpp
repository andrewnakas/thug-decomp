struct Entry_0018AEA0 {
    unsigned int m_key;
    void* m_value;
    Entry_0018AEA0* m_next;
};

extern "C" void* func_0010D3C8(int pool);
extern "C" Entry_0018AEA0* func_0018AC48(void* mem);

struct HashTable_0018AEA0 {
    int m_bits;
    Entry_0018AEA0* m_table;
    int m_count;
    bool Insert(const unsigned int* key, void* value);
};

bool HashTable_0018AEA0::Insert(const unsigned int* key, void* value)
{
    unsigned int k = *key;
    Entry_0018AEA0* b = &m_table[k & ((1 << m_bits) - 1)];
    if (b->m_value) {
        Entry_0018AEA0* e = func_0018AC48(func_0010D3C8(0));
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
