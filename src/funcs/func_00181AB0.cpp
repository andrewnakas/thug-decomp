struct Reg_00181AB0 {
    unsigned long lo : 26;
    unsigned long f : 4;
    unsigned long hi : 34;
};

struct Obj_00181AB0 {
    char pad[0x10];
    Reg_00181AB0 m_10;
    unsigned short Size();
};

unsigned short Obj_00181AB0::Size()
{
    unsigned short n = m_10.f;
    return 1 << n;
}
