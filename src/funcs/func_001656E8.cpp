struct Limits_001656E8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

extern Limits_001656E8 D_00360AE0[];

struct Obj_001656E8 {
    void Fn(int* w, int* h, int n);
};

void Obj_001656E8::Fn(int* w, int* h, int n)
{
    Limits_001656E8* t = &D_00360AE0[n];
    int cw = *w;
    if (t->m0 < cw) {
        int ch = *h;
        if (t->m4 >= ch)
            ch = t->m4;
        *h = ch;
        return;
    }
    if (*h > t->m4) {
        *w = t->m0;
        return;
    }
    if (cw < t->m8)
        *w = t->m8;
    if (*h < t->mC)
        *h = t->mC;
    if (*h > *w)
        *w = *h;
    if (*h * 2 < *w)
        *h = *w / 2;
}
