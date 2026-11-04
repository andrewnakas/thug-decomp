struct Node_00299EC0 {
    char pad0[0x2C];
    Node_00299EC0* m2C;
    Node_00299EC0* m30;
};

extern "C" void func_002994B8(Node_00299EC0* n, int v);

static inline int PostAdd_00299EC0(int& v, int d)
{
    int old = v;
    v += d;
    return old;
}

struct Obj_00299EC0 {
    int m0;
    int m4;
    int m8;
    Node_00299EC0* mC;
    int Layout(int v);
};

int Obj_00299EC0::Layout(int v)
{
    Node_00299EC0* n = mC;
    while (n && n->m2C)
        n = n->m2C;
    for (; n; n = n->m30)
        func_002994B8(n, PostAdd_00299EC0(v, 10));
    return v;
}
