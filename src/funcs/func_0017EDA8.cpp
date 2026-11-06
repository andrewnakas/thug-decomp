struct Reg_0017EDA8 {
    unsigned long lo : 30;
    unsigned long f : 4;
    unsigned long hi : 30;
};

struct Obj_0017EDA8 {
    char pad[0x28];
    Reg_0017EDA8 m_28;
    unsigned short Size();
};

unsigned short Obj_0017EDA8::Size()
{
    unsigned short n = m_28.f;
    return 1 << n;
}
