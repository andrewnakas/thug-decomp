struct Node_001EC720 {
    char pad[0x5C];
    Node_001EC720* m_prev;
    Node_001EC720* m_next;
};
extern int D_0038E6E4;
extern Node_001EC720* D_0038E6E0;
extern Node_001EC720* D_0038E6DC;
extern "C" void func_001EC8E0(Node_001EC720* n, int flags);
extern "C" void* func_001EE120(int size);
extern "C" Node_001EC720* func_001EC8C0(void* p);

extern "C" Node_001EC720* func_001EC720()
{
    if (D_0038E6E4 >= 100) {
        Node_001EC720* old = D_0038E6E0;
        Node_001EC720* next = old->m_next;
        if (old)
            func_001EC8E0(old, 3);
        D_0038E6E0 = next;
        if (next)
            next->m_prev = 0;
    }
    Node_001EC720* n = func_001EC8C0(func_001EE120(100));
    n->m_next = 0;
    n->m_prev = D_0038E6DC;
    if (D_0038E6DC)
        D_0038E6DC->m_next = n;
    else
        D_0038E6E0 = n;
    D_0038E6DC = n;
    return n;
}
