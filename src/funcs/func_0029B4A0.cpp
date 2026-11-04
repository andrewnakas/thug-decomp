struct Node_0029B4A0 {
    char pad0[0x2C];
    Node_0029B4A0* m2C;
};

struct Group_0029B4A0 {
    int m0;
    Group_0029B4A0* m4;
    int m8;
    Node_0029B4A0* mC;
};

struct Obj_0029B4A0 {
    char pad0[0x24];
    Group_0029B4A0* m24;
    int Count();
};

int Obj_0029B4A0::Count()
{
    int n = 0;
    for (Group_0029B4A0* g = m24; g; g = g->m4)
        for (Node_0029B4A0* p = g->mC; p; p = p->m2C)
            n++;
    return n;
}
