struct Ent_001E50C0 {
    int m0;
    unsigned int m4;
    int m8;
    int mC;
    Ent_001E50C0* m10;
};

extern Ent_001E50C0* D_0038E47C;
extern "C" void func_001E5678(Ent_001E50C0* e);
extern "C" void func_001E4F20(Ent_001E50C0* e);

extern "C" void func_001E50C0(Ent_001E50C0* e)
{
    Ent_001E50C0* bucket = &D_0038E47C[e->m4 & 0xFFF];
    if (e == bucket) {
        Ent_001E50C0* next = e->m10;
        if (next) {
            int* d = (int*)e;
            int* s = (int*)next;
            for (unsigned int i = 0; i < 5; i++) *d++ = *s++;
            next->mC = 0;
            func_001E5678(next);
        } else {
            func_001E4F20(e);
        }
    } else {
        Ent_001E50C0* p = bucket;
        Ent_001E50C0* n = p->m10;
        while (n && n != e) {
            p = n;
            n = p->m10;
        }
        p->m10 = e->m10;
        func_001E5678(e);
    }
}
