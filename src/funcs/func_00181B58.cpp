struct Tex_00181B58 {
    char pad0[0x10];
    unsigned long pad10 : 51;
    unsigned long m_cpsm : 4;
    unsigned long pad37 : 9;
    int Fn();
};

int Tex_00181B58::Fn()
{
    switch ((unsigned int)m_cpsm) {
    case 0:
        return 0x20;
    case 1:
        return 0x18;
    case 2:
        return 0x10;
    }
    return 0;
}
