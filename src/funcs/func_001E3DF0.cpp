struct Entry_001E3DF0 {
    char pad[0x104];
    void* m104;
};

extern Entry_001E3DF0 D_003F2BD0[];
extern "C" int func_00112618(void* p, void* q);

extern "C" bool func_001E3DF0(void* p, int i)
{
    void* q = D_003F2BD0[i].m104;
    if (!q)
        return false;
    return func_00112618(p, q) != 0;
}
