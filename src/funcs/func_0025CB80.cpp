struct Ent_0025CB80 {
    int m0;
    int m4;
};

struct Obj_0025CB80 {
    char pad[0x858];
    Ent_0025CB80 m858[64];
    int mA58;
    Ent_0025CB80* Fn(int id);
};

Ent_0025CB80* Obj_0025CB80::Fn(int id)
{
    for (int i = 0; i < mA58; i++) {
        if (m858[i].m0 == id) return &m858[i];
    }
    return 0;
}
