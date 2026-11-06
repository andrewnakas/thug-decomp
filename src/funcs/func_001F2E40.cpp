struct Node_001F2E40 {
    char m_pad0[0x10];
    Node_001F2E40* m10;
    Node_001F2E40* m14;
};

struct List_001F2E40 {
    char m_pad0[0x1C];
    Node_001F2E40* m1C;
    Node_001F2E40* m20;
    void Remove(Node_001F2E40* n);
};

void List_001F2E40::Remove(Node_001F2E40* n)
{
    if (n->m14)
        n->m14->m10 = n->m10;
    if (n->m10)
        n->m10->m14 = n->m14;
    if (n == m1C)
        m1C = n->m10;
    if (n == m20)
        m20 = n->m14;
    n->m10 = 0;
    n->m14 = 0;
}
