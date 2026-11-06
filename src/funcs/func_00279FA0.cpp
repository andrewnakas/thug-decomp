struct Obj_00279FA0 {
    char pad[0x4];
    unsigned short m_lo;
    unsigned short m_hi;
    unsigned int Get();
};

unsigned int Obj_00279FA0::Get()
{
    return (m_hi << 16) | m_lo;
}
