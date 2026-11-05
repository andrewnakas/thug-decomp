struct Obj_00290810 {
    char pad0[0x1C];
    unsigned int m1C;
    bool Flag2();
};

bool Obj_00290810::Flag2()
{
    if (m1C & 2)
        return true;
    return false;
}
