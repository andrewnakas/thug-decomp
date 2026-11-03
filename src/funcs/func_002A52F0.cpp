extern char D_00371C78[];

struct Iter_002A52F0 {
    int m0;
    int m4;
    void* m8;
    Iter_002A52F0() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A52F0() { m8 = D_00371C78; }
};

struct Sub_002A52F0 {
    char pad[0x18];
    int m18;
};

struct Elem_002A52F0 {
    char pad[0x18];
    Sub_002A52F0* m18;
};

extern "C" Elem_002A52F0* func_002A53F8(void* self, Iter_002A52F0* it, int a);
extern "C" Elem_002A52F0* func_002A5490(void* self, Iter_002A52F0* it, int a);

struct Table_002A52F0 {
    int m0;
    Elem_002A52F0* Find(unsigned short id);
};

Elem_002A52F0* Table_002A52F0::Find(unsigned short id)
{
    Iter_002A52F0 it;
    for (Elem_002A52F0* e = func_002A53F8(this, &it, 0); e; e = func_002A5490(this, &it, 0)) {
        if (e->m18 && e->m18->m18 == id)
            return e;
    }
    return 0;
}
