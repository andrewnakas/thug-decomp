struct Node_001DCE40 {
    int m_id;
    int m4;
    int m_active;
    int mC;
    Node_001DCE40* m_next;
    Node_001DCE40* m_prev;
};

extern Node_001DCE40* D_0038E0AC;
extern int D_0038E0B8;

extern "C" bool func_001DD678(void* mgr, int id, int a);
extern "C" void func_001DD448(void* mgr, int id);

extern "C" void func_001DCE40(void* mgr, Node_001DCE40* n, int stop)
{
    n->m_active = 0;
    if (stop) {
        if (func_001DD678(mgr, n->m_id, 0))
            func_001DD448(mgr, n->m_id);
    }
    if (n->m_next)
        n->m_next->m_prev = n->m_prev;
    if (n->m_prev)
        n->m_prev->m_next = n->m_next;
    else
        D_0038E0AC = n->m_next;
    D_0038E0B8--;
}
