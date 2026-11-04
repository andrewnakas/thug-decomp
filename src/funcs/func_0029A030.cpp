struct Node_0029A030 {
    char pad0[0x2C];
    Node_0029A030* m2C;
};

extern "C" void func_00299420(Node_0029A030* n, int v);

struct Obj_0029A030 {
    int m0;
    int m4;
    int m8;
    Node_0029A030* mC;
    void SetAll(int v);
};

void Obj_0029A030::SetAll(int v)
{
    for (Node_0029A030* n = mC; n; n = n->m2C)
        func_00299420(n, v);
}
