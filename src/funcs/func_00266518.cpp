extern void* D_0038FC78;
extern "C" void* func_0022E048(void* p);
extern "C" void* func_00265778(void* p, void* key);

struct Ring_00266518 {
    int m0;
    void* m_items[0x200];
    unsigned int m_count;
    int Add(void* p);
};

int Ring_00266518::Add(void* p)
{
    unsigned int n = m_count;
    if (n > 0x200)
        n = 0x200;
    p = func_00265778(func_0022E048(D_0038FC78), p);
    if (!p)
        return 0;
    for (unsigned int i = 0; i < n; i++) {
        if (m_items[i] == p)
            return 0;
    }
    m_items[m_count++ & 0x1FF] = p;
    return 0;
}
