struct Node_00299898 {
    char pad0[0x2C];
    Node_00299898* m2C;
};

struct Obj_00299898 {
    char pad0[0xC];
    Node_00299898* mC;
    int Count();
};

int Obj_00299898::Count()
{
    int n = 0;
    for (Node_00299898* p = mC; p; p = p->m2C)
        n++;
    return n;
}
