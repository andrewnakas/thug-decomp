extern "C" void func_0026CB98(void* p);

struct Node_0026D4E0 {
    int m0;
    int m4;
    int m8;
    Node_0026D4E0* mC;
    Node_0026D4E0* Valid()
    {
        Node_0026D4E0* r = 0;
        if (m4 != -1)
            r = this;
        return r;
    }
};

struct List_0026D4E0 {
    char pad[0x10];
    Node_0026D4E0* m10;
    void Run();
};

void List_0026D4E0::Run()
{
    for (Node_0026D4E0* n = m10->Valid(); n; n = n->mC->Valid())
        func_0026CB98(n);
}
