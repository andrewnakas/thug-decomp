struct Node_001A0730 {
    int m0;
    int m_tag;
    int m8;
    Node_001A0730* m_next;
    Node_001A0730* m_prev;
    virtual ~Node_001A0730();

    void Remove()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

static inline Node_001A0730* Valid_001A0730(Node_001A0730* n)
{
    Node_001A0730* r = 0;
    if (n->m_tag != -1) r = n;
    return r;
}

extern "C" int func_0011A220(Node_001A0730* n);

struct C_001A0730 {
    int m_pad[10];
    Node_001A0730* m28;
    void Purge();
};

void C_001A0730::Purge()
{
    Node_001A0730* n = Valid_001A0730(m28);
    while (n) {
        Node_001A0730* next = Valid_001A0730(n->m_next);
        if (!func_0011A220(n)) {
            n->Remove();
            delete n;
        }
        n = next;
    }
}
