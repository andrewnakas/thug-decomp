struct Obj_00170680 {
    int m0[7];
    unsigned int m_flags;
    int m_20;
    int m_24;
    int m28;
    int m_2C;
    int Get();
};

int Obj_00170680::Get()
{
    int r = 0;
    if (!(m_flags & 2))
        r = m_20;
    return r;
}
