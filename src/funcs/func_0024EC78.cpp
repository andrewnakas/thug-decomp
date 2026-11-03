struct Data_0024EC78 {
    int m0;
    virtual ~Data_0024EC78();
};

struct Node_0024EC78 {
    int m0;
    Data_0024EC78* m_data;
    int m8;
    Node_0024EC78* m_next;
    Node_0024EC78* m_prev;
    virtual ~Node_0024EC78();

    Node_0024EC78* Next()
    {
        Node_0024EC78* n = m_next;
        if ((int)n->m_data != -1)
            return n;
        return 0;
    }
    void Remove()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Owner_0024EC78 {
    int m_pad[6];
    Node_0024EC78* m_first;
    void Clear();
};

void Owner_0024EC78::Clear()
{
    Node_0024EC78* n = 0;
    Node_0024EC78* f = m_first;
    if ((int)f->m_data != -1)
        n = f;
    while (n) {
        Node_0024EC78* next = n->Next();
        n->Remove();
        delete n->m_data;
        delete n;
        n = next;
    }
}
