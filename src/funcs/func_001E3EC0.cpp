struct Ent_001E3EC0 {
    char pad[0x104];
    void* m104;
};
struct Res_001E3EC0 {
    int m0;
    int m4;
    int m8;
};
extern Ent_001E3EC0 D_003F2BD0[];
extern "C" Res_001E3EC0* func_001126C0(void* tbl, void* key);

int func_001E3EC0(void* tbl, int i)
{
    if (!D_003F2BD0[i].m104)
        return 0;
    Res_001E3EC0* r = func_001126C0(tbl, D_003F2BD0[i].m104);
    if (r)
        return r->m8;
    return 0;
}
