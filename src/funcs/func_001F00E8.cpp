struct Elem_001F00E8 {
    char pad[0xC];
    int mC;
    char pad2[0x2C - 0x10];
};
struct Obj_001F00E8 {
    char pad[0x38];
    int m38;
    char pad3C[0x94 - 0x3C];
    Elem_001F00E8* m94;
    char pad98[0xBC - 0x98];
    int mBC;
    bool Has(int id);
};

bool Obj_001F00E8::Has(int id)
{
    if (mBC == id)
        return true;
    for (int i = 0; i < m38; i++) {
        if (m94[i].mC == id)
            return true;
    }
    return false;
}
