struct Node_0026DC58 {
    int m0;
    int m4;
    int m8;
    Node_0026DC58* mC;
};

static inline Node_0026DC58* Next_0026DC58(Node_0026DC58* n)
{
    Node_0026DC58* p = n->mC;
    return ~p->m4 ? p : 0;
}

struct List_0026DC58 {
    char pad[0x10];
    Node_0026DC58* m10;
    Node_0026DC58* First()
    {
        if (!~m10->m4)
            return 0;
        return m10;
    }
    Node_0026DC58* Get(int idx);
};

Node_0026DC58* List_0026DC58::Get(int idx)
{
    Node_0026DC58* n = First();
    int i = 0;
    while (n) {
        if (i == idx)
            return n;
        n = Next_0026DC58(n);
        i++;
    }
    return 0;
}
