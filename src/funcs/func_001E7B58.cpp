struct Comp_001E7B58 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    int m8;
    Comp_001E7B58* mC;
};

struct Sym_001E7B58 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    int m4;
    int m8;
    int mC;
};

struct Struct_001E7B58 {
    int m0;
    Comp_001E7B58* m4;
};

extern "C" Sym_001E7B58* func_001E5040(int);

extern "C" int func_001E7B58(Struct_001E7B58* s, unsigned int name, unsigned int type, int* out)
{
    int found = 0;
    for (Comp_001E7B58* c = s->m4; c; c = c->mC) {
        if (c->m4 == name) {
            if (c->m1 == type) {
                found = 1;
                *out = c->m8;
            } else if (c->m1 == 13) {
                Sym_001E7B58* sym = func_001E5040(c->m8);
                if (sym && sym->m2 == type) {
                    found = 1;
                    *out = sym->mC;
                }
            }
        } else if (!c->m4) {
            if (c->m1 == 13) {
                Sym_001E7B58* sym = func_001E5040(c->m8);
                if (sym && sym->m2 == 10) {
                    int t;
                    if (func_001E7B58((Struct_001E7B58*)sym->mC, name, type, &t)) {
                        found = 1;
                        *out = t;
                    }
                }
            }
        }
    }
    return found;
}
