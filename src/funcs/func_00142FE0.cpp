extern "C" void* func_00331404(void* dst, const void* src, int n);

class Obj_00142FE0 {
public:
    int m_top;
    int m_size;
    char m_data[1];
    void Pop(void* dst);
};

void Obj_00142FE0::Pop(void* dst)
{
    m_top -= m_size;
    func_00331404(dst, m_data + m_top, m_size);
}
