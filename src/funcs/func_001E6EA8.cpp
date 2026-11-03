struct Comp_001E6EA8 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    unsigned int m8;
    Comp_001E6EA8* mC;
};

struct Sym_001E6EA8 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    int m4;
    int m8;
    void* mC;
};

struct Struct_001E6EA8 {
    int m0;
    Comp_001E6EA8* m4;
};

extern "C" Sym_001E6EA8* func_001E5040(unsigned int);
extern "C" void* func_001E8CD0(unsigned int);
extern "C" Comp_001E6EA8* func_001E4ED8(void*);
extern "C" void func_001E6360(Comp_001E6EA8*, Comp_001E6EA8*);
extern "C" void func_001E6F90(Struct_001E6EA8*, Comp_001E6EA8*);

extern "C" void func_001E6EA8(Struct_001E6EA8* s, Struct_001E6EA8* dst, int depth)
{
    for (Comp_001E6EA8* c = s->m4; c; c = c->mC) {
        int handled = 0;
        if (!c->m4 && c->m1 == 13) {
            Sym_001E6EA8* sym = func_001E5040(c->m8);
            if (sym && sym->m2 == 10) {
                func_001E6EA8((Struct_001E6EA8*)sym->mC, dst, depth + 1);
                handled = 1;
            }
        }
        if (!handled) {
            Comp_001E6EA8* n = func_001E4ED8(func_001E8CD0(16));
            func_001E6360(n, c);
            func_001E6F90(dst, n);
        }
    }
}
