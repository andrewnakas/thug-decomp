struct Block_0010C310 {
    int m0;
    int m_size;
};

extern "C" Block_0010C310* func_0010C3A0(void* p);

int func_0010C310(void* p)
{
    return func_0010C3A0(p)->m_size;
}
