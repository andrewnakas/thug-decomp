struct Reg_00181AD0 {
    unsigned long lo : 30;
    unsigned long f : 4;
    unsigned long hi : 30;
};

struct Obj_00181AD0 {
    char pad[0x10];
    Reg_00181AD0 m_10;
    unsigned short Size();
};

unsigned short Obj_00181AD0::Size()
{
    unsigned short n = m_10.f;
    return 1 << n;
}
