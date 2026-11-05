struct Node_0025FCA8 {
    int m0;
    int m4;
    int m8;
    Node_0025FCA8* mC;
    Node_0025FCA8* Valid() { if (~m4 == 0) return 0; return this; }
};

struct List_0025FCA8 {
    char pad0[0x54];
    Node_0025FCA8* m54;
    int Size()
    {
        int c = 0;
        for (Node_0025FCA8* n = m54->Valid(); n; n = n->mC->Valid()) c++;
        return c;
    }
    void* Fn(int last);
};

extern "C" Node_0025FCA8* func_0025F128(List_0025FCA8* l, int i);
extern "C" Node_0025FCA8* func_0025F1C8(List_0025FCA8* l);
extern "C" void* func_0025AAA8(Node_0025FCA8* n);

void* List_0025FCA8::Fn(int last)
{
    if (!Size()) return 0;
    Node_0025FCA8* n;
    if (!last) n = func_0025F128(this, 0);
    else n = func_0025F1C8(this);
    if (!n) return 0;
    return func_0025AAA8(n);
}
