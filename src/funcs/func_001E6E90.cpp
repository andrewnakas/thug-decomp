struct Node_001E6E90 {
    char pad0[0xC];
    int mC;
};
struct Obj_001E6E90 {
    int m0;
    int m4;
    int Get(Node_001E6E90* n);
};

int Obj_001E6E90::Get(Node_001E6E90* n)
{
    if (!n) return m4;
    return n->mC;
}
