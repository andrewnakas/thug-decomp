struct Ent_001EFFE8 {
    int m0;
    char pad[0x28];
};
struct Obj_001EFFE8 {
    char pad[0x38];
    int m38;
    char pad2[0x94 - 0x3C];
    Ent_001EFFE8* m94;
    char pad3[0xC8 - 0x98];
    int mC8;
    bool Has(int id);
};

bool Obj_001EFFE8::Has(int id)
{
    if (mC8 == id)
        return true;
    for (int i = 0; i < m38; i++) {
        if (m94[i].m0 == id)
            return true;
    }
    return false;
}
