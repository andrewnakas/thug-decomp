class Node_0014AEE8 {
public:
    int m0;
    int m4;
    int m8;
    Node_0014AEE8* mC;
    Node_0014AEE8* m10;
    Node_0014AEE8* Valid() { if (m4 == -1) return 0; return this; }
    virtual ~Node_0014AEE8();
};

extern Node_0014AEE8 D_003CBDC8;

extern "C" bool func_0014AEE8(int key)
{
    for (Node_0014AEE8* n = D_003CBDC8.mC->Valid(); n; n = n->mC->Valid()) {
        if (n->m4 == key) {
            delete n;
            return true;
        }
    }
    return false;
}
