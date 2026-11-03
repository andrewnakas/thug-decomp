extern char D_003714C0[];

struct Iter_002A5588 {
    int m0;
    int m4;
    void* m8;
    Iter_002A5588() { m8 = D_003714C0; m4 = 0; }
    ~Iter_002A5588() { m8 = D_003714C0; }
};

struct Elem_002A5588 {
    char pad[0x11];
    signed char m11;
};

extern "C" Elem_002A5588* func_002A5520(void* self, Iter_002A5588* it);
extern "C" Elem_002A5588* func_002A5558(void* self, Iter_002A5588* it);

struct Table_002A5588 {
    int m0;
    Elem_002A5588* Find(unsigned short id);
};

Elem_002A5588* Table_002A5588::Find(unsigned short id)
{
    Iter_002A5588 it;
    for (Elem_002A5588* e = func_002A5520(this, &it); e; e = func_002A5558(this, &it)) {
        if (e->m11 == id)
            return e;
    }
    return 0;
}
