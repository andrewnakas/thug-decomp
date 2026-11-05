struct Sym_001E5258 {
    unsigned int m_flags;
    int m4;
    int m8;
    int mC;
    Sym_001E5258* m_next;
    int Used() const { return (m_flags >> 9) & 1; }
};

extern Sym_001E5258* D_0038E47C;
extern unsigned int D_0038E484;
extern Sym_001E5258* D_0038E488;

static inline Sym_001E5258* Fail_001E5258()
{
    D_0038E484 = 0;
    D_0038E488 = 0;
    return 0;
}

extern "C" Sym_001E5258* func_001E5258(Sym_001E5258* prev)
{
    Sym_001E5258* p = prev;
    if (!p) {
        p = D_0038E47C;
        D_0038E484 = 0;
        while (!p->Used()) {
            p++;
            D_0038E484++;
            if (D_0038E484 >= 0x1000)
                return Fail_001E5258();
        }
        D_0038E488 = p;
        return p;
    }
    p = p->m_next;
    if (!p) {
        D_0038E484++;
        p = &D_0038E47C[D_0038E484];
        if (D_0038E484 >= 0x1000)
            return Fail_001E5258();
        while (!p->Used()) {
            p++;
            D_0038E484++;
            if (D_0038E484 >= 0x1000)
                return Fail_001E5258();
        }
    }
    D_0038E488 = p;
    return p;
}
