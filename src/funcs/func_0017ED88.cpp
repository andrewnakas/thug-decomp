struct Reg_0017ED88 {
    unsigned long lo : 26;
    unsigned long f : 4;
    unsigned long hi : 34;
};

struct Obj_0017ED88 {
    char pad[0x28];
    Reg_0017ED88 m_28;
    unsigned short Size();
};

unsigned short Obj_0017ED88::Size()
{
    unsigned short n = m_28.f;
    return 1 << n;
}
