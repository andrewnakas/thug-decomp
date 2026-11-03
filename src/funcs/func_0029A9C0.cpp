struct Grp_0029A9C0 {
    int m0;
    Grp_0029A9C0* next;
};

extern "C" bool func_0029A080(Grp_0029A9C0* g, float x0, float z0, float x1, float z1);

struct Obj_0029A9C0 {
    char pad[0x24];
    Grp_0029A9C0* m24;
    bool AnyIn(float x0, float z0, float x1, float z1);
};

bool Obj_0029A9C0::AnyIn(float x0, float z0, float x1, float z1)
{
    if (x1 < x0) {
        float t = x0;
        x0 = x1;
        x1 = t;
    }
    if (z1 < z0) {
        float t = z0;
        z0 = z1;
        z1 = t;
    }
    for (Grp_0029A9C0* g = m24; g; g = g->next) {
        if (func_0029A080(g, x0, z0, x1, z1))
            return true;
    }
    return false;
}
