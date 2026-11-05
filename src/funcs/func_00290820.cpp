struct Obj_00290820 {
    char pad[0x1C];
    int m1C;
    bool Flag10();
};

bool Obj_00290820::Flag10()
{
    if (m1C & 0x10)
        return true;
    return false;
}
