struct Node_0016DAF0;

struct List_0016DAF0 {
    char pad[0x20];
    Node_0016DAF0* m_head;
};

struct Node_0016DAF0 {
    char pad[0x1C];
    unsigned int m_flags;
    char pad20[8];
    Node_0016DAF0* m_next;
};

void Push_0016DAF0(Node_0016DAF0* n, List_0016DAF0* l)
{
    if (n->m_flags & 2) {
        n->m_next = 0;
        n->m_flags &= ~2;
    } else {
        n->m_next = l->m_head;
    }
    l->m_head = n;
}
