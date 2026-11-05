extern void* D_00393EB0;
extern "C" void func_0010A3D0(void* lock);
extern "C" void func_0010A3F8(void* lock);

struct Stack_0010A9B0 {
    char pad[0x8C];
    unsigned int* m_top;
    unsigned int m_items[16];
    int m_count;
    void Pop();
};

void Stack_0010A9B0::Pop()
{
    func_0010A3D0(D_00393EB0);
    m_count--;
    m_items[m_count] = 0xFFFFFFFF;
    if (m_count) {
        m_top = m_items + m_count - 1;
    } else {
        m_top = 0;
    }
    func_0010A3F8(D_00393EB0);
}
