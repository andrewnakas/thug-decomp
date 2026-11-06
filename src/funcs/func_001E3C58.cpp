struct Chan_001E3C58 {
    int m0;
    int m4;
    int m8;
};

extern unsigned int D_0038E280;
extern Chan_001E3C58* D_00351DF8[];

extern "C" int func_001E3C58(unsigned int ch)
{
    if (ch >= 3)
        return 0;
    if (D_0038E280 & (0x20000 << ch))
        return 4;
    if (D_0038E280 & (0x200 << ch))
        return 2;
    int st = D_00351DF8[ch]->m8;
    if (st)
        return (st != 4) ? 1 : 8;
    return 0x10;
}
