struct Ent_001AB758 {
    int m0;
    int m4;
    int m8, mC;
    int m10;
    int m14;
};
struct Obj_001AB758 {
    char pad[0x3C];
    Ent_001AB758 m3C[100];
    short m99C;
    short m99E;
    void Clear();
};

void Obj_001AB758::Clear()
{
    int i;
    for (i = 0; i < 100; i++) {
        m3C[i].m4 = 0;
        m3C[i].m10 = 0;
        m3C[i].m14 = 0;
    }
    m99C = 0;
    m99E = 0;
}
