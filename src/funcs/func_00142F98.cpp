struct Buf_00142F98 {
    int m_used;
    int m_size;
    char m_data[1];
};

extern "C" void* func_00331404(void* d, const void* s, int n);

extern "C" void func_00142F98(Buf_00142F98* b, const void* src)
{
    func_00331404(b->m_data + b->m_used, src, b->m_size);
    b->m_used += b->m_size;
}
