struct Obj_001FA6B0 {
    char pad0[0x2C8];
    int m2C8;
    int Not();
};

int Obj_001FA6B0::Not()
{
    return m2C8 ^ 1;
}
