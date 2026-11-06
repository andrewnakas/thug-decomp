class Node_001DAF58 {
public:
    int m0;
    void* m4;
    int m8;
    Node_001DAF58* mC;
    int m10;
    virtual ~Node_001DAF58();
    Node_001DAF58* Valid() { return ~(unsigned)m4 ? this : 0; }
};

extern Node_001DAF58* D_003E82EC[];

void func_001DAF58(void* obj)
{
    Node_001DAF58* n = D_003E82EC[0]->Valid();
    while (n) {
        Node_001DAF58* next = n->mC->Valid();
        if (n->m4 == obj) {
            delete n;
        }
        n = next;
    }
}
