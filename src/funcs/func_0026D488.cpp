extern "C" int func_0026CB68(void* p);
extern "C" void func_0026CC08(void* p, int v);

struct Node_0026D488 {
    int m0;
    int m4;
    int m8;
    Node_0026D488* mC;
    Node_0026D488* Valid()
    {
        Node_0026D488* r = 0;
        if (m4 != -1)
            r = this;
        return r;
    }
};

struct List_0026D488 {
    char pad[0x10];
    Node_0026D488* m10;
    void Bump();
};

void List_0026D488::Bump()
{
    for (Node_0026D488* n = m10->Valid(); n; n = n->mC->Valid())
        func_0026CC08(n, func_0026CB68(n) + 1);
}
