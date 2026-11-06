struct Entry_001AB950 {
    char pad0[0x10];
    int m0;
    int m4;
};

struct Obj_001AB950 {
    char pad[0x3C];
    Entry_001AB950 m3C[100];
    unsigned short m99C;
    unsigned short m99E;
    void Method();
};

void Obj_001AB950::Method()
{
    int idx = m99E;
    for (int i = 0; i < m99C; i++) {
        m3C[idx].m0 = 0;
        idx--;
        if (idx < 0)
            idx += 100;
    }
}
