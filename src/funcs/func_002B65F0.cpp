struct Node_002B65F0 {
    char pad0[0x10];
    unsigned short m10;
    char pad12[2];
    Node_002B65F0* m14;
};

struct List_002B65F0 {
    int m0;
    Node_002B65F0* m4;
    int Total() const;
};

int List_002B65F0::Total() const {
    int n = 0;
    for (Node_002B65F0* p = m4; p; p = p->m14) {
        n += p->m10;
    }
    return n;
}
