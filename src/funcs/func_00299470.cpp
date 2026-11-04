struct Vec_00299470 {
    float x, y, z, w;
};

struct Node_00299470 {
    char pad0[0x10];
    Vec_00299470 m10;
    char pad20[0xC];
    Node_00299470* m2C;
    Node_00299470* m30;
};

extern "C" bool func_00298160(Vec_00299470* a, Vec_00299470* b, Vec_00299470* c);

extern "C" bool func_00299470(Node_00299470* n)
{
    if (n->m2C && n->m30)
        return func_00298160(&n->m2C->m10, &n->m10, &n->m30->m10);
    return true;
}
