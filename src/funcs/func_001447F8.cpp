struct Entry_001447F8 {
    unsigned int m_key;
    void* m_value;
    Entry_001447F8* m_next;
};

extern "C" void* func_0010D3C8(int pool);
extern "C" Entry_001447F8* func_00144198(void* mem);

struct HashTable_001447F8 {
    int m_bits;
    Entry_001447F8* m_table;
    int m_count;
    bool Insert(const unsigned int* key, void* value);
};

bool HashTable_001447F8::Insert(const unsigned int* key, void* value)
{
    unsigned int k = *key;
    Entry_001447F8* b = &m_table[k & ((1 << m_bits) - 1)];
    if (b->m_value) {
        Entry_001447F8* e = func_00144198(func_0010D3C8(0));
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
