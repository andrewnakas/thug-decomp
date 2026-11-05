struct Ent_001E5430 {
    char pad0[0xC];
    int mC;
};
extern "C" Ent_001E5430* func_001E5040(void* p);

int Get_001E5430(void* p)
{
    Ent_001E5430* e = func_001E5040(p);
    if (!e) return 0;
    return e->mC;
}
