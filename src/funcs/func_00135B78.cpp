extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_00135B78 {
    int m0;
    void* m_4;
    void Free();
};

void Obj_00135B78::Free()
{
    if (m_4) {
        func_0010A8D8(D_00388A70, m_4);
        m_4 = 0;
    }
}
