struct Node_0025F0F0 {
    int m0;
    int m4;
    int m8;
    Node_0025F0F0* mC;
    Node_0025F0F0* Valid() { if (~m4 == 0) return 0; return this; }
};

struct List_0025F0F0 {
    char pad0[0x54];
    Node_0025F0F0* m54;
    int Size();
};

int List_0025F0F0::Size()
{
    int c = 0;
    for (Node_0025F0F0* n = m54->Valid(); n; n = n->mC->Valid()) c++;
    return c;
}
