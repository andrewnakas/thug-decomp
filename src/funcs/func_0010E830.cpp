extern volatile int D_00388C90;

struct File_0010E830 {
    int m0[4];
    int m_op;
    int m14[8];
    volatile int m_count;
    void Release();
};

void File_0010E830::Release()
{
    D_00388C90--;
    m_count--;
    if (m_count == 0)
        m_op = 0;
}
