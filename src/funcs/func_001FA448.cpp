struct Obj_001FA448 {
    char pad0[0x138];
    int m138;
    char pad13C[0x2D0 - 0x13C];
    int m2D0;
    void Set(int v);
};

void Obj_001FA448::Set(int v)
{
    if (m138 != v) {
        if (m138) m2D0 = 1;
        m138 = v;
    }
}
