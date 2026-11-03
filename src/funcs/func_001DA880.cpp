struct Obj_001DA880 {
    unsigned int m_bits;
    unsigned int Get();
};

unsigned int Obj_001DA880::Get()
{
    return m_bits & 1;
}
