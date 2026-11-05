extern char D_003763B0[];

struct S_0026D0A8 {
    int m0;
    unsigned int m4;
    int m8;
    S_0026D0A8* mC;
    S_0026D0A8* m10;
    char* m14;
};

struct C_0026D0A8 {
    int m0;
    S_0026D0A8 m4;
};

static inline void Init_0026D0A8(S_0026D0A8* s)
{
    s->m4 = 0xFFFFFFFF;
    s->m8 = 0;
    s->mC = s;
    s->m10 = s;
    s->m14 = D_003763B0;
}

extern "C" C_0026D0A8* func_0026D0A8(C_0026D0A8* p)
{
    Init_0026D0A8(&p->m4);
    p->m0 = 0;
    return p;
}
