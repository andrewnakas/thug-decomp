extern char D_003668B8[];

struct C_001FA720 {
    int m0;
    C_001FA720* m4;
    int m8;
    C_001FA720* mC;
    C_001FA720* m10;
    char* m14;
    char m18, m19, m1A, m1B;
    int m1C[3];
    int m28;
    int m2C;
};

extern "C" C_001FA720* func_001FA720(C_001FA720* p, int a)
{
    p->m4 = p;
    p->m8 = 0;
    p->mC = p;
    p->m10 = p;
    p->m14 = D_003668B8;
    p->m1A = 0;
    p->m28 = 0;
    p->m18 = 0;
    p->m2C = a;
    return p;
}
