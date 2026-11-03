struct Comp_001E8618 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    unsigned int m8;
    Comp_001E8618* mC;
};

struct Sym_001E8618 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    int m4;
    int m8;
    void* mC;
};

struct Struct_001E8618 {
    int m0;
    Comp_001E8618* m4;
};

extern "C" Sym_001E8618* func_001E5040(unsigned int);

extern "C" int func_001E8618(Struct_001E8618* s, unsigned int name)
{
    for (Comp_001E8618* c = s->m4; c; c = c->mC) {
        if (c->m4 == name)
            return 1;
        if (!c->m4 && c->m1 == 13) {
            if (c->m8 == name)
                return 1;
            Sym_001E8618* sym = func_001E5040(c->m8);
            if (sym && sym->m2 == 10) {
                if (func_001E8618((Struct_001E8618*)sym->mC, name))
                    return 1;
            }
        }
    }
    return 0;
}
