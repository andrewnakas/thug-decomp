struct Voice_001E36D8 {
    int m0;
    int m4;
    int m8;
    char pad[0x10];
    int m1C;
};
extern Voice_001E36D8* D_00351DF8[];

int func_001E36D8(int i, float vol)
{
    if (vol > 100.0f)
        vol = 100.0f;
    int v = (int)(vol * 40.96f);
    if (!v)
        return 0;
    Voice_001E36D8* p = D_00351DF8[i];
    if (p->m8 == 4)
        return 0;
    p->m1C = v;
    return 1;
}
