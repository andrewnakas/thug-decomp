struct Obj_002C6A28 {
    char pad0[0x34];
    int m34;
    bool Fits(int a, int b) const;
};

bool Obj_002C6A28::Fits(int a, int b) const {
    return a * b * 40000 < m34;
}
