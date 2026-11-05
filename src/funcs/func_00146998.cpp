extern "C" void func_00170578(void* o, int v);

struct Obj_00146998 {
    int m0[12];
    void* m_30;
    int m34[20];
    int m_84;
    void Set(int v);
};

void Obj_00146998::Set(int v)
{
    if (m_84 != v) {
        m_84 = v;
        if (m_30)
            func_00170578(m_30, v);
    }
}
