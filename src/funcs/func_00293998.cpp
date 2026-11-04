struct Obj_00293998 {
    char pad[0x30C];
    unsigned char m30C[10];
    unsigned char m316;
    bool Has(unsigned char v);
};

bool Obj_00293998::Has(unsigned char v)
{
    for (int i = 0; i < m316; i++) {
        if (m30C[i] == v)
            return true;
    }
    return false;
}
