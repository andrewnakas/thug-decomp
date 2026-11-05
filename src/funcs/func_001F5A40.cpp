struct Obj_001F5A40 {
    unsigned int m0;
    unsigned int m4;
    int m8;
    unsigned int Get(unsigned int a);
};

unsigned int Obj_001F5A40::Get(unsigned int a)
{
    if (a == ((m8 * 16 + m4 + 16) & 0x0FFFFFFF))
        return 0;
    return (a - m0) >> 11;
}
