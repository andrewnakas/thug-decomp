struct Node_001F2E08 {
    char pad[0x10];
    Node_001F2E08* m_next;
    Node_001F2E08* m_prev;
};
struct List_001F2E08 {
    char pad[0x1C];
    Node_001F2E08* m_head;
    Node_001F2E08* m_tail;
    void AddHead(Node_001F2E08* n);
};

void List_001F2E08::AddHead(Node_001F2E08* n)
{
    n->m_prev = 0;
    n->m_next = m_head;
    m_head = n;
    if (n->m_next)
        n->m_next->m_prev = n;
    if (!m_tail)
        m_tail = m_head;
}
