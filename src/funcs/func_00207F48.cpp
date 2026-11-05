struct Obj_00207F48 {
    char pad[0x24];
    int m24;
    int m28;
    int* m2C;
    bool Has(int v);
};

bool Obj_00207F48::Has(int v)
{
    for (int i = 0; i < m24; i++) {
        if (m2C[i] == v)
            return true;
    }
    return false;
}
