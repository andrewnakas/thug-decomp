extern "C" void func_002682E0(void* a, void* b, void* c, void* d);

struct Node_00268420 {
    char pad0[0x10];
    char m_10[0x10];
    char m_20[0x10];
    char m_30[0x20];
    Node_00268420* m_50;
    Node_00268420* m_54;
    int m_58;
};

struct Mgr_00268420 {
    void Link(Node_00268420* a, Node_00268420* b);
};

void Mgr_00268420::Link(Node_00268420* a, Node_00268420* b)
{
    if (!a->m_50) {
        a->m_50 = b;
        func_002682E0(a->m_30, b->m_30, a->m_10, a->m_20);
    } else if (b->m_58 & 2) {
        a->m_50 = b;
        func_002682E0(a->m_30, b->m_30, a->m_10, a->m_20);
    }
    if (!b->m_54 || (a->m_58 & 2)) {
        b->m_54 = a;
    }
}
