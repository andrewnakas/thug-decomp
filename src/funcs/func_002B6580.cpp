struct Node_002B6580 {
    char pad0[0x14];
    Node_002B6580* m14;
};

struct List_002B6580;
extern "C" void func_002B62C0(Node_002B6580* n);
extern "C" void func_002B68A0(List_002B6580* l, Node_002B6580* n);

struct List_002B6580 {
    int m0;
    Node_002B6580* m4;
    Node_002B6580* m8;
    short mC;
    void Clear();
};

void List_002B6580::Clear()
{
    Node_002B6580* n = m4;
    while (n) {
        Node_002B6580* next = n->m14;
        func_002B62C0(n);
        func_002B68A0(this, n);
        n = next;
    }
    m4 = 0;
    m8 = 0;
    mC = 0;
}
