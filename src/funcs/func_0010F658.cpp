struct Ent_0010F658 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Tbl_0010F658 {
    char pad0[0x10];
    int m_count;
    char pad14[4];
    Ent_0010F658 ents[1];
    Ent_0010F658* Find(int a, int b);
};

Ent_0010F658* Tbl_0010F658::Find(int a, int b)
{
    for (int i = 0; i < m_count; i++) {
        if (ents[i].m8 == a && ents[i].mC == b) return &ents[i];
    }
    return 0;
}
