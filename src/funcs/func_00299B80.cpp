struct Node_00299B80 {
    char pad0[0x2C];
    Node_00299B80* m2C;
};

struct Obj_00299B80 {
    int m0;
    int m4;
    int m8;
    Node_00299B80* mC;
    Node_00299B80* At(int k);
};

Node_00299B80* Obj_00299B80::At(int k)
{
    Node_00299B80* n = mC;
    while (k && n) {
        n = n->m2C;
        k--;
    }
    return n;
}
