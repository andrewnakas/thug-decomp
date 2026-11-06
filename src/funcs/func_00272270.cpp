struct Node_00272270 {
    int m0;
    int m_key;
    int m8;
    Node_00272270* m_next;
    char m_pad10[0x1C];
    int m2C;
    int m30;
    int m34;
    Node_00272270* Valid()
    {
        if (m_key == -1)
            return 0;
        return this;
    }
};

extern "C" void func_00184BC0(void* a, int b, int c, int d, int e, int f);

struct Obj_00272270 {
    char m_pad0[0xC];
    void* mC;
    char m_pad10[0x30];
    Node_00272270* m_head;
    void Apply();
};

void Obj_00272270::Apply()
{
    Node_00272270* next;
    for (Node_00272270* n = m_head->Valid(); n; n = next) {
        next = n->m_next->Valid();
        if (n->m34)
            func_00184BC0(mC, n->m30, n->m2C, 0, 0, 0);
    }
}
