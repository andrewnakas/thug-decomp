struct Node_001048F0 {
    int m0;
    int m4;
    int m8;
    Node_001048F0* m_prev;
    Node_001048F0* m_next;
    void Unlink()
    {
        m_next->m_prev = m_prev;
        m_prev->m_next = m_next;
        m_prev = this;
        m_next = this;
    }
};

struct List_001048F0 {
    int m0;
    int m_refs;
};

extern "C" void func_00104D10(List_001048F0* list);

struct Task_001048F0 {
    int m0;
    int m4;
    Node_001048F0* m_node;
    List_001048F0* m_list;
    void Remove();
};

void Task_001048F0::Remove()
{
    if (m_list) {
        m_list->m_refs++;
        func_00104D10(m_list);
        m_node->Unlink();
        m_list->m_refs--;
        m_list = 0;
    }
}
