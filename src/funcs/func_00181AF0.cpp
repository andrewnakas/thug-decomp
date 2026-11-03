struct Tex00181AF0 {
    char pad[0x10];
    unsigned long m_reg;
    int GetDepth() const;
};

int Tex00181AF0::GetDepth() const
{
    switch ((int)((m_reg >> 20) & 0x3F)) {
    case 0:
        return 32;
    case 1:
        return 24;
    case 2:
        return 16;
    case 0x13:
        return 8;
    case 0x14:
        return 4;
    default:
        return 0;
    }
}
