extern "C" void func_0026CC18(void* p);

struct Node_0026D5D0 {
    int m0;
    int m4;
    int m8;
    Node_0026D5D0* mC;
    Node_0026D5D0* Valid()
    {
        Node_0026D5D0* r = 0;
        if (m4 != -1)
            r = this;
        return r;
    }
};

struct List_0026D5D0 {
    char pad[0x10];
    Node_0026D5D0* m10;
    void Run();
};

void List_0026D5D0::Run()
{
    for (Node_0026D5D0* n = m10->Valid(); n; n = n->mC->Valid())
        func_0026CC18(n);
}
