struct Ch_0029B3D0 {
    int m0;
    Ch_0029B3D0* m4;
    char pad8[0x10 - 8];
    int m10;
};

struct Obj_0029B3D0 {
    char pad[0x24];
    Ch_0029B3D0* m24;
    Ch_0029B3D0* Find(int id);
};

Ch_0029B3D0* Obj_0029B3D0::Find(int id)
{
    for (Ch_0029B3D0* c = m24; c; c = c->m4) {
        if (c->m10 == id)
            return c;
    }
    return 0;
}
