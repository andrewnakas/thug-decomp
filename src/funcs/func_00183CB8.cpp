struct Node_00183CB8 {
    void* m_list;
    Node_00183CB8* m_prev;
    Node_00183CB8* m_next;
};

struct List_00183CB8 {
    int m0;
    Node_00183CB8* m_head;
};

extern "C" void func_00183CB8(List_00183CB8* list, Node_00183CB8* n)
{
    if (n->m_prev) {
        n->m_prev->m_next = n->m_next;
    } else {
        list->m_head = n->m_next;
    }
    if (n->m_next) {
        n->m_next->m_prev = n->m_prev;
    }
    n->m_prev = 0;
    n->m_next = 0;
}
