struct Node_0017E0B0 {
    char pad0[8];
    void* m8;
    void* mC;
    char pad10[0x3C];
    Node_0017E0B0* m_next;
};

extern Node_0017E0B0* D_0038C0F8;
extern void* D_00388A70;
extern "C" void func_0010BEB8(void* p);
extern "C" void func_0017B4D8();
extern "C" void func_0010A8D8(void* heap, void* p);

extern "C" void func_0017E0B0(Node_0017E0B0* n, int flags)
{
    if (D_0038C0F8 == n) {
        D_0038C0F8 = n->m_next;
    } else if (D_0038C0F8) {
        Node_0017E0B0* p = D_0038C0F8;
        while (p->m_next) {
            if (p->m_next == n) {
                p->m_next = n->m_next;
                break;
            }
            p = p->m_next;
        }
    }
    if (n->m8) {
        func_0010BEB8(n->m8);
    }
    if (n->mC) {
        func_0010BEB8(n->mC);
    }
    func_0017B4D8();
    if (flags & 1) {
        func_0010A8D8(D_00388A70, n);
    }
}
