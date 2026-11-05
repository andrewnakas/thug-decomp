struct Obj_001E3A90 {
    int m0;
    int m4;
    int m8;
};
extern int D_0038E280;
extern Obj_001E3A90* D_00351DF8[];

bool func_001E3A90(int i)
{
    int mask = 0x2000 << i;
    bool r = false;
    if (D_0038E280 & mask)
        r = D_00351DF8[i]->m8 == 2;
    return r;
}
