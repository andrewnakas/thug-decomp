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

void Chain_00243A70::Clear()
{
    Link_00243A70* p = m_first;
    while (p) {
        Link_00243A70* next = p->m_next;
        func_0010A8D8(D_00388A70, p);
        p = next;
    }
    m_first = 0;
    m_cursor = 0;
    m_count = 0;
}
