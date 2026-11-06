struct Node_00189C88 {
    int m0[3];
    Node_00189C88* m_next;
    int m_10;
};

struct List_00189C88 {
    int m0[5];
    Node_00189C88* m_head;
    void Push(Node_00189C88* n);
};

void List_00189C88::Push(Node_00189C88* n)
{
    n->m_next = m_head;
    m_head = n;
    n->m_10 = 1;
}
