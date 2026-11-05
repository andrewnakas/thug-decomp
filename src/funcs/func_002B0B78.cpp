struct Sk_002B0B78 {
    char pad[0x18];
    int m18;
};

struct Pl_002B0B78 {
    char pad[0x18];
    Sk_002B0B78* m18;
};

struct Mgr_002B0B78 {
    char pad[0x10];
    void* m10;
};

struct Obj_002B0B78 {
    int m0;
    char pad4[0x14 - 4];
    int m14;
    char pad18[4];
    Mgr_002B0B78* m1C;
};

extern "C" Pl_002B0B78* func_002A5248(Mgr_002B0B78* m, int id);
extern "C" void func_002DA118(void* p, int a, int b);

extern "C" bool func_002B0B78(Obj_002B0B78* o)
{
    Mgr_002B0B78* m = o->m1C;
    func_002DA118(m->m10, func_002A5248(m, o->m14)->m18->m18, o->m0);
    return true;
}
