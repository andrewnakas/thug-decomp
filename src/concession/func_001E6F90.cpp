/* force: {"kind": "ga", "before": [118, 117]} */
struct Comp_001E6F90 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    unsigned int m8;
    Comp_001E6F90* mC;
};

struct Struct_001E6F90 {
    int m0;
    Comp_001E6F90* m4;
};

extern "C" void func_001E6250(Comp_001E6F90*);
extern "C" void func_001E8D20(Comp_001E6F90*);

extern "C" void func_001E6F90(Struct_001E6F90* s, Comp_001E6F90* n)
{
    Comp_001E6F90* prev = 0;
    Comp_001E6F90* c = s->m4;
    while (c) {
        if (c->m4 == n->m4) {
            int same = 0;
            if (c->m1 == n->m1) {
                if (n->m1 != 13 || c->m4 != 0 || c->m8 == n->m8)
                    same = 1;
            } else if ((c->m1 == 2 && n->m1 == 1) || (c->m1 == 1 && n->m1 == 2)) {
                same = 1;
            }
            if (same) {
                if (prev) {
                    prev->mC = c->mC;
                    func_001E6250(c);
                    func_001E8D20(c);
                    c = prev->mC;
                } else {
                    s->m4 = c->mC;
                    func_001E6250(c);
                    func_001E8D20(c);
                    c = s->m4;
                }
                continue;
            }
        }
        prev = c;
        c = prev->mC;
    }
    if (prev)
        prev->mC = n;
    else
        s->m4 = n;
    n->mC = 0;
}
