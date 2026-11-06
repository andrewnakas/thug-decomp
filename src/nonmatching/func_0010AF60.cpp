/* fuzzy: 95.1 */
extern "C" void* func_001046B0(int size);
extern "C" void* func_0010D0B0(void* p, int a, int b, int c);

struct List_0010AF60 {
    int m0;
    void* m_items[32];
    int m_count;
    void Add(int a, int b, int c);
};

void List_0010AF60::Add(int a, int b, int c)
{
    void* p = func_0010D0B0(func_001046B0(0x84), a, b, c);
    int n = m_count;
    m_items[n] = p;
    m_count = n + 1;
}
