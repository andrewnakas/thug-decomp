struct Obj_001F7EB8 {
    char pad0[0x48];
    int m48;
    char pad4C[0x54 - 0x4C];
    int m54;
    bool Full();
};

bool Obj_001F7EB8::Full()
{
    return m54 >= m48;
}
