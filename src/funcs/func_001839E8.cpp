struct Obj_001839E8 {
    int m0[7];
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    void Clear(unsigned int f);
};

void Obj_001839E8::Clear(unsigned int f)
{
    m_1C &= ~f;
    m_20 &= ~f;
    m_24 &= ~f;
}
