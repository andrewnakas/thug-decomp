struct Node_00183C98 {
    void* m_list;
    Node_00183C98* m_prev;
    Node_00183C98* m_next;
};

struct List_00183C98 {
    int m0;
    Node_00183C98* m_head;
};

extern "C" void func_00183C98(List_00183C98* list, Node_00183C98* n)
{
    n->m_next = list->m_head;
    if (list->m_head) {
        list->m_head->m_prev = n;
    }
    list->m_head = n;
}
