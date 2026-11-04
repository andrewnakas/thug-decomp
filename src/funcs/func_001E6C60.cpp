struct Comp_001E6C60 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    unsigned int m8;
    Comp_001E6C60* mC;
};

struct Struct_001E6C60 {
    int m0;
    Comp_001E6C60* m4;
};

extern "C" void func_001E6250(Comp_001E6C60*);
extern "C" void func_001E8D20(Comp_001E6C60*);

extern "C" void func_001E6C60(Struct_001E6C60* s, unsigned int name, unsigned char type)
{
    Comp_001E6C60* prev = 0;
    Comp_001E6C60* c = s->m4;
    Comp_001E6C60* next;
    if (c) do {
        next = c->mC;
        if (c->m4 == name && c->m1 == type) {
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
