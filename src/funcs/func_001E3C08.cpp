struct Obj_001E3C08 {
    int m0;
    int m4;
    int m8;
};
extern int D_0038E280;
extern Obj_001E3C08* D_0038E284;

int func_001E3C08()
{
    int fl = D_0038E280;
    if (fl & 0x10000)
        return 4;
    if (fl & 0x100)
        return 2;
    int t = D_0038E284->m8;
    if (t)
        return t != 4 ? 1 : 8;
    return 16;
}
