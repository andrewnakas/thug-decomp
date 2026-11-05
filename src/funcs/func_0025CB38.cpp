struct Ent_0025CB38 {
    int m0;
    char pad[0x1C];
};

struct Obj_0025CB38 {
    char pad[0x54];
    Ent_0025CB38 m54[64];
    int m854;
    Ent_0025CB38* Fn(int id);
};

Ent_0025CB38* Obj_0025CB38::Fn(int id)
{
    for (int i = 0; i < m854; i++) {
        if (m54[i].m0 == id) return &m54[i];
    }
    return 0;
}
