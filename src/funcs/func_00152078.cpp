struct Entry_00152078 {
    unsigned int m_key;
    void* m_value;
    Entry_00152078* m_next;
};

extern "C" void* func_0010D3C8(int pool);
extern "C" Entry_00152078* func_00144278(void* mem);

struct HashTable_00152078 {
    int m_bits;
    Entry_00152078* m_table;
    int m_count;
    bool Insert(const unsigned int* key, void* value);
};

bool HashTable_00152078::Insert(const unsigned int* key, void* value)
{
    unsigned int k = *key;
    Entry_00152078* b = &m_table[k & ((1 << m_bits) - 1)];
    if (b->m_value) {
        Entry_00152078* e = func_00144278(func_0010D3C8(0));
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
