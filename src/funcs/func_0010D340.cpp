struct Node_0010D340 {
    void* m_next;
};

struct List_0010D340 {
    int m0[4];
    int m_count;
    Node_0010D340* m_head;
    void Push(Node_0010D340* n);
};

void List_0010D340::Push(Node_0010D340* n)
{
    m_count--;
    n->m_next = m_head;
    m_head = n;
}
