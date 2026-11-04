struct Obj_001DA868 {
    unsigned int m_bits;
    unsigned int Get();
};

unsigned int Obj_001DA868::Get()
{
    return m_bits & 0xFFFFFFFC;
}
