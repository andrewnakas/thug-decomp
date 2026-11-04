struct Node_0029B2F8 {
    int m0;
    Node_0029B2F8* m4;
    Node_0029B2F8* m8;
};

extern "C" void func_00299588(Node_0029B2F8* n, int f);

struct List_0029B2F8 {
    char pad[0x24];
    Node_0029B2F8* m24;
    Node_0029B2F8* m28;
    void Remove(Node_0029B2F8* n);
};

void List_0029B2F8::Remove(Node_0029B2F8* n)
{
    if (m24 == n)
        m24 = n->m4;
    if (m28 == n)
        m28 = n->m4;
    if (n->m4)
        n->m4->m8 = n->m8;
    if (n->m8)
        n->m8->m4 = n->m4;
    if (n)
        func_00299588(n, 3);
}
