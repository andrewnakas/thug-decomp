extern char D_00371C78[];

struct Iter_002A7598 {
    int m0;
    int m4;
    void* m8;
    Iter_002A7598() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A7598() { m8 = D_00371C78; }
};

struct Comp_002A7598 {
    char pad[0x1C];
    void* m1C;
};

struct Elem_002A7598 {
    char pad[0x18];
    void* m18;
    char pad1C[0x14C - 0x1C];
    int m14C;
};

struct Obj_002A7598;
extern "C" Elem_002A7598* func_002A53F8(Obj_002A7598* o, Iter_002A7598* it, int f);
extern "C" Elem_002A7598* func_002A5490(Obj_002A7598* o, Iter_002A7598* it, int f);
extern "C" Comp_002A7598* func_00185578(void* p, unsigned int name);
extern "C" void func_002381E0(void* p);

struct Obj_002A7598 {
    void ResetAll();
};

void Obj_002A7598::ResetAll()
{
    Iter_002A7598 it;
    for (Elem_002A7598* e = func_002A53F8(this, &it, 1); e; e = func_002A5490(this, &it, 1)) {
        e->m14C &= ~0x100;
        if (e->m18) {
            Comp_002A7598* c = func_00185578(e->m18, 0xD262802F);
            if (c->m1C) func_002381E0(c->m1C);
        }
    }
}
