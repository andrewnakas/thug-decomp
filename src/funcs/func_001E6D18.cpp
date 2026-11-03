struct Comp_001E6D18 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    unsigned int m8;
    Comp_001E6D18* mC;
};

struct Struct_001E6D18 {
    int m0;
    Comp_001E6D18* m4;
};

extern "C" void func_001E6250(Comp_001E6D18*);
extern "C" void func_001E8D20(Comp_001E6D18*);

extern "C" void func_001E6D18(Struct_001E6D18* s, unsigned int val)
{
    Comp_001E6D18* prev = 0;
    Comp_001E6D18* c = s->m4;
    Comp_001E6D18* next;
    if (c) do {
        next = c->mC;
        if (!c->m4 && c->m8 == val) {
            if (prev)
                prev->mC = next;
            else
                s->m4 = next;
            func_001E6250(c);
            func_001E8D20(c);
        } else {
            prev = c;
        }
        c = next;
    } while (next);
}
