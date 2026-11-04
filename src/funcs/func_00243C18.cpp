extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);

struct Link_00243A70 {
    int m_key;
    int m_value;
    Link_00243A70* m_next;
    Link_00243A70();
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Chain_00243A70 {
    int m0;
    int m_count;
    Link_00243A70* m_first;
    Link_00243A70* m_last;
    Link_00243A70* m_cursor;
    int m_pos;
    void Clear();
    bool Append(const int& key, int value);
    int Get(const int& index, int* key);
    void Remove(const int& key);
    int Find(const int& key);
    ~Chain_00243A70();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

int Chain_00243A70::Get(const int& index, int* key)
{
    if (m_cursor) {
        if (m_pos != index) {
            if (m_pos < index) {
                while (m_pos < index) {
                    m_pos++;
                    m_cursor = m_cursor->m_next;
                }
            } else {
                m_cursor = 0;
            }
        }
    }
    if (!m_cursor) {
        Link_00243A70* p = m_first;
        for (int i = 0; i < index; i++)
            p = p->m_next;
        m_pos = index;
        m_cursor = p;
    }
    if (key)
        *key = m_cursor->m_key;
    return m_cursor->m_value;
}
