struct Grp_0029AB30 {
    int m0;
    Grp_0029AB30* next;
};

extern "C" void* func_00299A18(Grp_0029AB30* g, void* list, float x0, float z0, float x1, float z1);

struct Obj_0029AB30 {
    char pad[0x24];
    Grp_0029AB30* m24;
    void* Collect(float x0, float z0, float x1, float z1);
};

void* Obj_0029AB30::Collect(float x0, float z0, float x1, float z1)
{
    void* list = 0;
    for (Grp_0029AB30* g = m24; g; g = g->next)
        list = func_00299A18(g, list, x0, z0, x1, z1);
    return list;
}
