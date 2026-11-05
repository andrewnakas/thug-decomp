extern char D_00366A60[];

struct C_001FBF30 {
    int m0;
    C_001FBF30* m4;
    int m8;
    C_001FBF30* mC;
    C_001FBF30* m10;
    char* m14;
    int m18;
    int m1C;
    int m20;
};

extern "C" C_001FBF30* func_001FBF30(C_001FBF30* p, int a, int b, int c, int d)
{
    p->m4 = p;
    p->m8 = d;
    p->mC = p;
    p->m10 = p;
    p->m14 = D_00366A60;
    p->m18 = a;
    p->m1C = c;
    p->m20 = b;
    return p;
}
