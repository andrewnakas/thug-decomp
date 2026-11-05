struct Ent_001F2A00 {
    int m0;
    int m4;
};
struct Obj_001F2A00 {
    char pad0[0x14C];
    Ent_001F2A00 m14C[19];
    int m1E4;
    int m1E8;
    void Inc();
};

void Obj_001F2A00::Inc()
{
    m14C[m1E8].m0++;
}
