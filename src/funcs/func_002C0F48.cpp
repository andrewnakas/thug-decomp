struct Rec_002C0F48 {
    char pad0[8];
    unsigned short m8;
    char padA[4];
    unsigned char mE;
    unsigned char mF;
    unsigned short m10;
    unsigned short m12;
    char pad14[4];
    unsigned int m18;
};

struct Obj_002C0F48 {
    void Get(Rec_002C0F48* r, int* a, int* b, short* c, unsigned int* d, int* e, int* f);
};

void Obj_002C0F48::Get(Rec_002C0F48* r, int* a, int* b, short* c, unsigned int* d, int* e, int* f)
{
    *e = r->mE;
    *f = r->mF;
    *a = r->m12;
    *b = r->m10;
    *c = r->m8;
    if (r->m18)
        *d = r->m18;
    else
        *d = 0x1CA1FF20;
}
