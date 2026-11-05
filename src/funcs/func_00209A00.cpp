struct Obj_00209A00 {
    char pad0[0x74];
    int m74;
    char pad78[0xC0 - 0x78];
    int mC0;
    char padC4[0xCC - 0xC4];
    int mCC;
    int Check();
};

int Obj_00209A00::Check()
{
    if (mC0) return 1;
    if (mCC) {
        mCC = 0;
        m74 = 0;
    }
    return 0;
}
