struct Obj_0023D5D8 {
    char pad0[0x2C];
    int m2C;
    bool Has(int v);
};

bool Obj_0023D5D8::Has(int v)
{
    return m2C >= v;
}
