struct In_0014A528 {
    char pad[0x158];
    short m_158;
    short m_15A;
};

struct Obj_0014A528 {
    int m0[2];
    In_0014A528* m_8;
    void Set(int a, int b);
};

void Obj_0014A528::Set(int a, int b)
{
    m_8->m_158 = a;
    if (b > 0)
        m_8->m_15A = b;
}
