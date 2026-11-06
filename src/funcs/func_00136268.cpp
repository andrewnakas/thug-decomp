struct Rec_00136268 {
    int m[12];
};

extern int D_00389E38;
extern Rec_00136268 D_003BEC60[256];

Rec_00136268* Alloc_00136268()
{
    int n = D_00389E38;
    if (n < 256) {
        n++;
        D_00389E38 = n;
        return &D_003BEC60[n];
    }
    return 0;
}
