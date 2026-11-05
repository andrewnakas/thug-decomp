struct Ent_001F4FF0 {
    int m0;
    char pad4[0x20];
};
struct Obj_001F4FF0 {
    char pad0[0x30];
    Ent_001F4FF0 m30[1];
    int Get(int i);
};

int Obj_001F4FF0::Get(int i)
{
    return m30[i].m0;
}
