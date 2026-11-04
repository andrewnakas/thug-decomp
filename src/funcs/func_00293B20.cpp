struct Ent_00293B20 {
    unsigned char id;
    char pad[3];
};

struct Obj_00293B20 {
    char pad[0x2E0];
    Ent_00293B20 ents[10];
    int m308;
    Ent_00293B20* Find(int id);
};

Ent_00293B20* Obj_00293B20::Find(int id)
{
    for (int i = 0; i < m308; i++) {
        if (ents[i].id == id)
            return &ents[i];
    }
    return 0;
}
