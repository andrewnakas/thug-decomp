struct Ent_00109598 {
    char pad0[0x10];
    void* m10;
};

struct Cur_00109598 {
    char pad0[0x10];
    Ent_00109598* m10;
};

struct Mgr_00109598 {
    int m0;
    Cur_00109598* m4;
};

extern Mgr_00109598* D_00388A30;
extern int D_00388A34;
extern "C" int func_00108A00(Mgr_00109598* mgr, int a);

extern "C" void* func_00109598(int a)
{
    if (func_00108A00(D_00388A30, a)) {
        D_00388A34 = 1;
        Ent_00109598* e = D_00388A30->m4->m10;
        return e ? e->m10 : 0;
    }
    D_00388A34 = 0;
    return 0;
}
