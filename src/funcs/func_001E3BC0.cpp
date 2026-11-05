struct Obj_001E3BC0 {
    int m0;
    int m4;
    int m8;
};
extern int D_0038E280;
extern Obj_001E3BC0* D_0038E284;

bool Is_001E3BC0()
{
    bool r = false;
    if (D_0038E280 & 0x1000) r = D_0038E284->m8 == 2;
    return r;
}
