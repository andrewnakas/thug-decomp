struct Node_002B7940 {
    int m0;
    unsigned int m4;
    Node_002B7940* m8;
};

struct List_002B7940 {
    unsigned int m0;
    Node_002B7940* m4;
    void Push(Node_002B7940* n);
};

void List_002B7940::Push(Node_002B7940* n) {
    n->m4 |= 8;
    n->m8 = m4;
    m4 = n;
    m0 |= 8;
}
