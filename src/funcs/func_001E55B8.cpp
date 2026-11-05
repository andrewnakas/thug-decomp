struct Obj_001E55B8 {
    char m0;
    char m1;
    unsigned char m2;
    char pad[9];
    int mC;
};
extern "C" Obj_001E55B8* func_001E5040();

int func_001E55B8()
{
    Obj_001E55B8* p = func_001E5040();
    if (p && p->m2 == 12)
        return p->mC;
    return 0;
}
