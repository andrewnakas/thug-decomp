struct Node_001A0718 {
    int m0;
    int m4;
};
struct Obj_001A0718 {
    char pad[0x28];
    Node_001A0718* m28;
    Node_001A0718* Get();
};

Node_001A0718* Obj_001A0718::Get()
{
    Node_001A0718* n = m28;
    if (n->m4 == -1) return 0;
    return n;
}
