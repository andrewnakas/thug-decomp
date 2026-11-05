extern char D_0038F330[];
extern char D_003F5390[];
extern void* D_00394140;
extern char* D_00394144;
extern int D_0038F32C;
extern "C" void* func_00110E38(void* p, void* name);

bool func_0020AE90(void* p)
{
    void* v = func_00110E38(p, D_0038F330);
    D_00394140 = v;
    D_00394144 = D_003F5390;
    if (v)
        D_0038F32C = 1;
    return v != 0;
}
