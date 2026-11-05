struct Obj_0023D668 {
    char pad0[0x34];
    int m34;
    bool Use(int n);
};

bool Obj_0023D668::Use(int n)
{
    if (m34 >= n) {
        m34 -= n;
        return true;
    }
    return false;
}
