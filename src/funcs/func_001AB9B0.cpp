struct Entry_001AB9B0 {
    char pad0[0x10];
    int m0;
    unsigned int m4;
};

struct Obj_001AB9B0 {
    char pad[0x3C];
    Entry_001AB9B0 m3C[100];
    unsigned short m99C;
    unsigned short m99E;
    void Method(unsigned int flags);
};

void Obj_001AB9B0::Method(unsigned int flags)
{
    int idx = m99E;
    for (int i = 0; i < m99C; i++) {
        if (m3C[idx].m0) {
            m3C[idx].m0 = 0;
            m3C[idx].m4 |= flags;
        }
        idx--;
        if (idx < 0)
            idx += 100;
    }
}
