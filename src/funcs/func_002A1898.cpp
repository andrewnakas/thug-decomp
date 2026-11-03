struct Obj_002A1838 {
    char pad0[0x20];
    struct Inner* m20;
    char pad24[0x38 - 0x24];
    int m38;
    int m3C;
    char pad40[0x168 - 0x40];
    int m_flags;
    void SetMode(int mode);
};

void Obj_002A1838::SetMode(int mode) {
    int f = m_flags & ~0xC;
    m_flags = f;
    if (mode == 1) {
        m_flags = f | 8;
    } else if (mode == 2) {
        m_flags = f | 4;
    }
}
