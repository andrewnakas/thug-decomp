struct Node_00299970 {
    char pad0[0x10];
    float x;
    float y;
    float z;
    char pad1C[0x2C - 0x1C];
    Node_00299970* m2C;
};

struct Obj_00299970 {
    int m0;
    int m4;
    int m8;
    Node_00299970* mC;
    int CountIn(float x0, float z0, float x1, float z1);
};

int Obj_00299970::CountIn(float x0, float z0, float x1, float z1)
{
    int n = 0;
    for (Node_00299970* p = mC; p; p = p->m2C) {
        if (x0 < p->x && p->x < x1 && z0 < p->z && p->z < z1)
            n++;
    }
    return n;
}
