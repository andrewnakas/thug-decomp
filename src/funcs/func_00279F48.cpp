struct Obj_00279F48 {
    char pad[0x80];
    unsigned short m_lo;
    unsigned short m_hi;
    unsigned int Get();
};

unsigned int Obj_00279F48::Get()
{
    return (m_hi << 16) | m_lo;
}
