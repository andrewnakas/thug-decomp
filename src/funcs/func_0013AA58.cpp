struct Entry_0013AA58 {
    unsigned int m_key;
    void* m_value;
    Entry_0013AA58* m_next;
};

extern "C" void* func_0010D3C8(int pool);
extern "C" Entry_0013AA58* func_0013AA30(void* mem);

struct HashTable_0013AA58 {
    int m_bits;
    Entry_0013AA58* m_table;
    int m_count;
    bool Insert(const unsigned int* key, void* value);
};

bool HashTable_0013AA58::Insert(const unsigned int* key, void* value)
{
    unsigned int k = *key;
    Entry_0013AA58* b = &m_table[k & ((1 << m_bits) - 1)];
    if (b->m_value) {
        Entry_0013AA58* e = func_0013AA30(func_0010D3C8(0));
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
