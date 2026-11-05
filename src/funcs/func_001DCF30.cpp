struct Node_001DCF30 {
    int m0;
    int m_sub;
    int m8;
    int m_id;
    Node_001DCF30* m_next;
};

extern Node_001DCF30* D_0038E0AC;

extern "C" void func_001DCE40(void* a, Node_001DCF30* n, int b);

extern "C" void func_001DCF30(void* a, int id, int sub)
{
    Node_001DCF30* next = D_0038E0AC;
    while (next) {
        Node_001DCF30* n = next;
        next = n->m_next;
        if (n->m_id == id && (!sub || n->m_sub == sub))
            func_001DCE40(a, n, 1);
    }
}
