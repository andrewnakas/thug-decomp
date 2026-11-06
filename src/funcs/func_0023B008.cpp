extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);

struct Array_0023B008 {
    int m0;
    void** m_items;
    int m8;
    int m_count;
    void RemoveAt(int i);
};

void Array_0023B008::RemoveAt(int i)
{
    func_0010A8D8(D_00388A70, m_items[i]);
    for (; i < m_count - 1; i++)
        m_items[i] = m_items[i + 1];
    m_items[m_count - 1] = 0;
    m_count--;
}
