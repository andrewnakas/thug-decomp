struct Node_002B6290 {
    char pad0[0x28];
    Node_002B6290* m28;
};

struct List_002B6290 {
    int m0;
    int m4;
    Node_002B6290* m8;
    Node_002B6290* mC;
    unsigned short m10;
    void Append(Node_002B6290* n);
};

void List_002B6290::Append(Node_002B6290* n) {
    if (m8 == 0) {
        m8 = n;
    } else {
        mC->m28 = n;
    }
    mC = n;
    m10++;
}
