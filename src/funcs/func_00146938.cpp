extern "C" void func_00170810(void* o, unsigned char v);

struct Obj_00146938 {
    int m0[12];
    void* m_30;
    void Set(int v);
};

void Obj_00146938::Set(int v)
{
    if (m_30)
        func_00170810(m_30, v);
}
