extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);

struct Link_0023AE88 {
    int m_key;
    int m_value;
    Link_0023AE88* m_next;
    Link_0023AE88();
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Chain_0023AE88 {
    int m0;
    int m_count;
    Link_0023AE88* m_first;
    Link_0023AE88* m_last;
    Link_0023AE88* m_cursor;
    int m_pos;
    void Clear();
    bool Append(const int& key, int value);
    int Get(const int& index, int* key);
    void Remove(const int& key);
    int Find(const int& key);
    ~Chain_0023AE88();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

int Chain_0023AE88::Find(const int& key)
{
    m_cursor = 0;
    m_pos = 0;
    for (Link_0023AE88* p = m_first; p; p = p->m_next) {
        if (p->m_key == key) {
            m_cursor = p;
            return p->m_value;
        }
        m_pos++;
    }
    return 0;
}
