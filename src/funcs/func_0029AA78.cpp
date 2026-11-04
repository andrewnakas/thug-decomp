struct Grp_0029AA78 {
    int m0;
    Grp_0029AA78* next;
};

extern "C" int func_00299970(Grp_0029AA78* g, float x0, float z0, float x1, float z1);

struct Obj_0029AA78 {
    char pad[0x24];
    Grp_0029AA78* m24;
    int CountIn(float x0, float z0, float x1, float z1);
};

int Obj_0029AA78::CountIn(float x0, float z0, float x1, float z1)
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
    int n = 0;
    for (Grp_0029AA78* g = m24; g; g = g->next)
        n += func_00299970(g, x0, z0, x1, z1);
    return n;
}
