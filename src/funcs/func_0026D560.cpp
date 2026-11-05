extern "C" int func_0026CB68(void* p);

struct Node_0026D560 {
    int m0;
    int m4;
    int m8;
    Node_0026D560* mC;
    Node_0026D560* Valid()
    {
        Node_0026D560* r = 0;
        if (m4 != -1)
            r = this;
        return r;
    }
};

struct List_0026D560 {
    char pad[0x10];
    Node_0026D560* m10;
    Node_0026D560* First()
    {
        if (!~m10->m4)
            return 0;
        return m10;
    }
    int All();
};

static inline int All_0026D560(Node_0026D560* n)
{
    for (; n; n = n->mC->Valid()) {
        if (!func_0026CB68(n))
            return 0;
    }
    return 1;
}

int List_0026D560::All()
{
    return All_0026D560(First());
}
