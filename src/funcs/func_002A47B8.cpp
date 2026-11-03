struct Node_002A47B8 {
    char pad0[0xC];
    Node_002A47B8* m_next;
    Node_002A47B8* m_prev;
};

struct List_002A47B8 {
    char pad0[0xDC];
    Node_002A47B8 m_head;
    void AddTail(Node_002A47B8* node);
};

void List_002A47B8::AddTail(Node_002A47B8* node) {
    Node_002A47B8* head = &m_head;
    node->m_prev = head->m_prev;
    node->m_next = head;
    head->m_prev->m_next = node;
    head->m_prev = node;
}
