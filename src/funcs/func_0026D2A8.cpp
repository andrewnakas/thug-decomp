extern "C" void* func_0026CBB0(void* p);
extern "C" int func_00331950(void* a, void* b);
extern "C" void func_0026CB88(void* p);

struct Node_0026D2A8 {
    int m0;
    int m4;
    int m8;
    Node_0026D2A8* mC;
    Node_0026D2A8* Valid()
    {
        Node_0026D2A8* r = 0;
        if (m4 != -1)
            r = this;
        return r;
    }
};

struct List_0026D2A8 {
    char pad[0x10];
    Node_0026D2A8* m10;
    void Run(void* name);
};

void List_0026D2A8::Run(void* name)
{
    Node_0026D2A8* n;
    for (n = m10->Valid(); n; n = n->mC->Valid()) {
        if (!func_00331950(func_0026CBB0(n), name))
            break;
    }
    if (n)
        func_0026CB88(n);
}
