struct Node_002B6628 {
    int m0;
    int m4;
    char pad8[0xC];
    Node_002B6628* m14;
};

struct List_002B6628 {
    int m0;
    Node_002B6628* m4;
    Node_002B6628* Find(int key, int index) const;
};

Node_002B6628* List_002B6628::Find(int key, int index) const {
    int i = 0;
    for (Node_002B6628* p = m4; p; p = p->m14) {
        if (p->m4 == key) {
            if (i == index) {
                return p;
            }
            i++;
        }
    }
    return 0;
}
