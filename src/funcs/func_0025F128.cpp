struct Node_0025F128 {
    int m0;
    int m4;
    int m8;
    Node_0025F128* mC;
};

struct List_0025F128;
extern "C" int func_0025F0F0(List_0025F128* self);

static inline Node_0025F128* Next_0025F128(Node_0025F128* n)
{
    Node_0025F128* p = n->mC;
    return ~p->m4 ? p : 0;
}

struct List_0025F128 {
    char pad0[0x54];
    Node_0025F128* m54;
    Node_0025F128* First()
    {
        if (!~m54->m4)
            return 0;
        return m54;
    }
    Node_0025F128* GetItem(unsigned int idx)
    {
        Node_0025F128* p = First();
        while (p) {
            if (idx-- == 0)
                return p;
            p = Next_0025F128(p);
        }
        return 0;
    }
    Node_0025F128* Fn(unsigned int i);
};

Node_0025F128* List_0025F128::Fn(unsigned int i)
{
    if (!func_0025F0F0(this))
        return 0;
    return GetItem(i);
}
