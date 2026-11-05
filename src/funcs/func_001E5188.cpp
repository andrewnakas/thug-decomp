struct Ent_001E5188 {
    unsigned int m0;
    int Used() { return (m0 >> 9) & 1; }
    unsigned int m4;
    int m8;
    int mC;
    Ent_001E5188* m10;
};

extern Ent_001E5188* D_0038E47C;
extern "C" void func_001E4F20(Ent_001E5188* e);
extern "C" void* func_001E5728(int size);
extern "C" Ent_001E5188* func_001E4EF8(void* p);

extern "C" Ent_001E5188* func_001E5188(unsigned int key)
{
    Ent_001E5188* e = &D_0038E47C[key & 0xFFF];
    if (!e->Used()) {
        func_001E4F20(e);
        e->m4 = key;
        e->m0 |= 0x300;
        return e;
    }
    Ent_001E5188* last = 0;
    if (e) {
        do {
            last = e;
            e = e->m10;
        } while (e);
    }
    Ent_001E5188* ne = func_001E4EF8(func_001E5728(0x14));
    ne->m4 = key;
    ne->m0 |= 0x300;
    ne->m10 = 0;
    last->m10 = ne;
    return ne;
}
