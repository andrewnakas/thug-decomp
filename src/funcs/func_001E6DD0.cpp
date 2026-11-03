struct Comp_001E6DD0 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    unsigned int m8;
    Comp_001E6DD0* mC;
};

struct Sym_001E6DD0 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    int m4;
    int m8;
    void* mC;
};

struct Struct_001E6DD0 {
    int m0;
    Comp_001E6DD0* m4;
};

extern "C" Sym_001E6DD0* func_001E5040(unsigned int);

extern "C" Comp_001E6DD0* func_001E6DD0(Struct_001E6DD0* s, unsigned int name)
{
    Comp_001E6DD0* found = 0;
    for (Comp_001E6DD0* c = s->m4; c; c = c->mC) {
        if (c->m4 == name) {
            found = c;
        } else if (!c->m4 && c->m1 == 13) {
            Sym_001E6DD0* sym = func_001E5040(c->m8);
            if (sym && sym->m2 == 10) {
                Comp_001E6DD0* r = func_001E6DD0((Struct_001E6DD0*)sym->mC, name);
                if (r)
                    found = r;
            }
        }
    }
    return found;
}
