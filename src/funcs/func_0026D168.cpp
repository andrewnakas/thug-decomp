extern "C" void* func_0026CBB0(void* p);
extern "C" int func_00331950(void* a, void* b);

struct Node_0026D168 {
    int m0;
    int m4;
    int m8;
    Node_0026D168* mC;
    Node_0026D168* Valid()
    {
        Node_0026D168* r = 0;
        if (m4 != -1)
            r = this;
        return r;
    }
};

struct Head_0026D168 {
    int m0;
    int m4;
    int m8;
    Node_0026D168* mC;
    Node_0026D168* First()
    {
        if (!~mC->m4)
            return 0;
        return mC;
    }
};

struct List_0026D168 {
    int m0;
    Head_0026D168 m4;
    Node_0026D168* First() { return m4.First(); }
    int Find(void* name);
};

int List_0026D168::Find(void* name)
{
    int i = 0;
    for (Node_0026D168* n = First(); n; n = n->mC->Valid()) {
        if (!func_00331950(func_0026CBB0(n), name))
            return i;
        i++;
    }
    return -1;
}
