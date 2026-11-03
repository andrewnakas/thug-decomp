extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);

struct Link_00263278 {
    int m_key;
    int m_value;
    Link_00263278* m_next;
    Link_00263278();
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Chain_00263278 {
    int m0;
    int m_count;
    Link_00263278* m_first;
    Link_00263278* m_last;
    Link_00263278* m_cursor;
    int m_pos;
    void Clear();
    bool Append(const int& key, int value);
    int Get(const int& index, int* key);
    void Remove(const int& key);
    int Find(const int& key);
    ~Chain_00263278();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

bool Chain_00263278::Append(const int& key, int value)
{
    Link_00263278* n = new Link_00263278;
    n->m_value = value;
    n->m_key = key;
    if (!m_first)
        m_first = n;
    else
        m_last->m_next = n;
    m_last = n;
    m_cursor = 0;
    m_count++;
    return true;
}
