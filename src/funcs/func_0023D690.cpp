struct Obj_0023D690 {
    char pad0[0x34];
    int m34;
    int m38;
    int Get(int k);
};

int Obj_0023D690::Get(int k)
{
    if (k) return m38;
    return m34;
}
