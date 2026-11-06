struct E8_001D67C8 {
    unsigned short m0;
    unsigned short m2;
    int m4;
};

struct E10_001D67C8 {
    unsigned short m0;
    unsigned short m2;
    unsigned short m4[3];
};

struct T_001D67C8 {
    char m_pad[0xA];
    unsigned char mA;
    char mB;
    void* mC;
};

struct C_001D67C8 {
    char m_pad[8];
    T_001D67C8* m8;
    int Get(int i);
};

int C_001D67C8::Get(int i)
{
    T_001D67C8* t = m8;
    return t->mA ? ((E8_001D67C8*)t->mC)[i].m2 : ((E10_001D67C8*)t->mC)[i].m2;
}
