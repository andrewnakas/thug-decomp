struct Node_002B6550 {
    char pad0[0x14];
    Node_002B6550* m14;
};

struct List_002B6550 {
    int m0;
    Node_002B6550* m4;
    Node_002B6550* m8;
    unsigned short mC;
    void Append(Node_002B6550* n);
};

void List_002B6550::Append(Node_002B6550* n) {
    if (m4 == 0) {
        m4 = n;
    } else {
        m8->m14 = n;
    }
    m8 = n;
    mC++;
}
