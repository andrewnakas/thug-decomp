struct Array_0023B0C0 {
    int m0;
    int* m_data;
    int m_capacity;
    int m_size;
    int m_grow;
    void Add(int value);
};

extern "C" void* func_0010BDE0(int size);
extern "C" void func_0010BEB8(void* p);

void Array_0023B0C0::Add(int value)
{
    if (m_size >= m_capacity) {
        int capacity = m_capacity + m_grow;
        int* data = (int*)func_0010BDE0(capacity * 4);
        int i;
        for (i = 0; i < m_capacity; i++) {
            data[i] = m_data[i];
        }
        for (i = m_capacity; i < capacity; i++) {
            data[i] = 0;
        }
        func_0010BEB8(m_data);
        m_data = data;
        m_capacity = capacity;
    }
    m_data[m_size++] = value;
}
