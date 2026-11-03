struct Obj_002A1838 {
    char pad0[0x20];
    struct Inner* m20;
    char pad24[0x38 - 0x24];
    int m38;
    int m3C;
    char pad40[0x168 - 0x40];
    int m_flags;
    int GetM3C() const;
};

int Obj_002A1838::GetM3C() const {
    return m3C;
}
