struct Ent_001A3620 {
    int key;
    char pad[0x2C];
};
struct Obj_001A3620 {
    char pad[0x3C];
    Ent_001A3620 m3C[2];
    Ent_001A3620* Find(int key);
};

Ent_001A3620* Obj_001A3620::Find(int key)
{
    int i;
    for (i = 0; i < 2; i++) {
        if (m3C[i].key == key) {
            return &m3C[i];
        }
    }
    return 0;
}
