extern char D_00371C78[];

struct Iter_002A5248 {
    int m0;
    int m4;
    void* m8;
    Iter_002A5248() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A5248() { m8 = D_00371C78; }
};

struct Elem_002A5248 {
    char pad[0x1C];
    int m1C;
};

extern "C" Elem_002A5248* func_002A53F8(void* self, Iter_002A5248* it, int a);
extern "C" Elem_002A5248* func_002A5490(void* self, Iter_002A5248* it, int a);

struct Table_002A5248 {
    int m0;
    Elem_002A5248* Find(int id);
};

Elem_002A5248* Table_002A5248::Find(int id)
{
    Iter_002A5248 it;
    for (Elem_002A5248* e = func_002A53F8(this, &it, 1); e; e = func_002A5490(this, &it, 1)) {
        if (e->m1C == id)
            return e;
    }
    return 0;
}
