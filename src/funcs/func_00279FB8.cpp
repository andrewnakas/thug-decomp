struct Obj_00279FB8 {
    char pad[0x4];
    unsigned short m_lo;
    unsigned short m_hi;
    void Set(unsigned int v);
};

void Obj_00279FB8::Set(unsigned int v)
{
    m_lo = v;
    m_hi = v >> 16;
}
