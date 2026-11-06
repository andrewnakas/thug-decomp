struct Obj_001F0CD0 {
    char pad0[0xCC];
    int mCC;
    int mD0;
};

int Get_001F0CD0(Obj_001F0CD0* o)
{
    if (o == 0)
        return 0;
    if ((o->mCC & 1) == 0)
        return 0;
    return o->mD0;
}
