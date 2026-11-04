struct Box_002CD5A0 {
    char pad[7];
    unsigned char m7;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
};

extern "C" void func_002CD5A0(Box_002CD5A0* b, unsigned char x, unsigned char y)
{
    if (x < b->m7)
        b->m7 = x;
    if (x > b->m9)
        b->m9 = x;
    if (y < b->m8)
        b->m8 = y;
    if (y > b->mA)
        b->mA = y;
}
