extern "C" void* func_0010BDE0(int size);

struct Array_0023AF30 {
    int m0;
    int* m_data;
    int m_size;
    int m_count;
    int m_10;
    Array_0023AF30(int size, int v);
};

Array_0023AF30::Array_0023AF30(int size, int v)
{
    m_10 = v;
    m_size = size;
    m_data = (int*)func_0010BDE0(size * 4);
    for (int i = 0; i < m_size; i++) {
        m_data[i] = 0;
    }
    m_count = 0;
}
