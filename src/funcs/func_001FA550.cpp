extern char D_0038EB88[];
struct Obj_001FA550 {
    char pad[0x1A0];
    char m1A0[4];
    char* GetName();
};
extern "C" int func_001FA648(Obj_001FA550* self);

char* Obj_001FA550::GetName()
{
    if (func_001FA648(this) == 3)
        return D_0038EB88;
    return m1A0;
}
