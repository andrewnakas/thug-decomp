struct Node_0025F708 {
    int m0;
    int m4;
    int m8;
    Node_0025F708* mC;
    Node_0025F708* Valid() { if (~m4 == 0) return 0; return this; }
};

struct List_0025F708 {
    char pad0[0x54];
    Node_0025F708* m54;
    int Size()
    {
        int c = 0;
        for (Node_0025F708* n = m54->Valid(); n; n = n->mC->Valid()) c++;
        return c;
    }
    bool Apply(int last, void* arg);
};

extern "C" Node_0025F708* func_0025F128(List_0025F708* l, int i);
extern "C" Node_0025F708* func_0025F1C8(List_0025F708* l);
extern "C" void func_0025AB40(Node_0025F708* n, void* arg);

bool List_0025F708::Apply(int last, void* arg)
{
    if (!Size()) return false;
    if (!last) {
        func_0025AB40(func_0025F128(this, 0), arg);
        return true;
    }
    Node_0025F708* n = func_0025F1C8(this);
    if (n) func_0025AB40(n, arg);
    return true;
}
