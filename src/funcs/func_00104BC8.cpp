struct Node_00104BC8 {
    int m0;
    int m_data;
    int m_pri;
    Node_00104BC8* m_prev;
    Node_00104BC8* m_next;
    void* m_vtbl;
    Node_00104BC8* Valid()
    {
        return m_data != -1 ? this : 0;
    }
    void InsertAfter(Node_00104BC8* n)
    {
        Node_00104BC8* next = n->m_next;
        m_prev = n;
        m_next = next;
        n->m_next->m_prev = this;
        n->m_next = this;
    }
};

struct List_00104BC8;

struct Task_00104BC8 {
    int m0;
    int m4;
    Node_00104BC8* m_node;
    List_00104BC8* m_list;
    int m10;
};

struct List_00104BC8 {
    int m0;
    int m_refs;
    Node_00104BC8 m_head;
    int m20;
    int m_dirty;
    void Add(Task_00104BC8* t);
};

void List_00104BC8::Add(Task_00104BC8* t)
{
    m_refs++;
    Node_00104BC8* head = &m_head;
    Node_00104BC8* node = t->m_node;
    Node_00104BC8* p = head->m_prev;
    int pri = node->m_pri;
    Node_00104BC8* n;
    while ((n = p->Valid()) != 0) {
        if (pri >= n->m_pri) {
            node->InsertAfter(n);
            goto done;
        }
        p = n->m_prev;
    }
    node->InsertAfter(head);
done:
    t->m_list = this;
    t->m10 = m20 - 1;
    m_dirty = 1;
    m_refs--;
}
