struct Grp_0029A8C8 {
    int m0;
    Grp_0029A8C8* next;
};

struct Obj_0029A8C8;
extern "C" bool func_0029A7C0(Obj_0029A8C8* o, Grp_0029A8C8* g, float x0, float z0, float x1, float z1, bool flag);
extern "C" void func_0029B400(Obj_0029A8C8* o);

struct Obj_0029A8C8 {
    char pad[0x24];
    Grp_0029A8C8* m24;
    void ClipAll(float x0, float z0, float x1, float z1, bool flag);
};

void Obj_0029A8C8::ClipAll(float x0, float z0, float x1, float z1, bool flag)
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
    bool again;
    do {
        again = false;
        for (Grp_0029A8C8* g = m24; g; g = g->next) {
            if (func_0029A7C0(this, g, x0, z0, x1, z1, flag))
                again = true;
        }
    } while (again);
    func_0029B400(this);
}
