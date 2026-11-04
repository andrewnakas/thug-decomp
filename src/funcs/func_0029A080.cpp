struct Node_0029A080 {
    char pad[0x10];
    float m10;
    float m14;
    float m18;
    char pad1C[0x2C - 0x1C];
    Node_0029A080* m2C;
};

struct Obj_0029A080 {
    char pad[0xC];
    Node_0029A080* mC;
    int Outside(float x0, float z0, float x1, float z1);
};

int Obj_0029A080::Outside(float x0, float z0, float x1, float z1)
{
    for (Node_0029A080* n = mC; n; n = n->m2C) {
        if (n->m10 < x0 || x1 < n->m10 || n->m18 < z0 || z1 < n->m18)
            return 1;
    }
    return 0;
}
