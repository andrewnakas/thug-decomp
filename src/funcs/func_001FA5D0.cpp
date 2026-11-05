struct Obj_001FA5D0 {
    char pad[0x2B0];
    int m2B0;
    int Get();
};
extern "C" int func_001FA648(Obj_001FA5D0* self);

int Obj_001FA5D0::Get()
{
    if (func_001FA648(this) == 3)
        return 1;
    return m2B0;
}
