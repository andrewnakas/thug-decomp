extern "C" void func_00170810(void* o, unsigned char v);

struct Obj_0014D998 {
    int m0[8];
    void* m_20;
    void Set(int v);
};

void Obj_0014D998::Set(int v)
{
    if (m_20)
        func_00170810(m_20, v);
}
