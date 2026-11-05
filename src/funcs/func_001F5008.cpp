struct Ent_001F5008 {
    int m0;
    char pad4[0x20];
};
struct Obj_001F5008 {
    char pad0[0x30];
    Ent_001F5008 m30[69];
    char pad9E4[0xA00 - 0x9E4];
    int mA00;
    void Set(int i, int v);
};

void Obj_001F5008::Set(int i, int v)
{
    m30[i].m0 = v;
    if (v == 1) mA00 = v;
}
