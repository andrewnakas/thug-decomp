struct Node_002713D8 {
    int m0;
    void* m_data;
    int m8;
    Node_002713D8* m_next;
    Node_002713D8* m_prev;
    virtual ~Node_002713D8();

    Node_002713D8* Next()
    {
        Node_002713D8* n = m_next;
        if ((int)n->m_data != -1)
            return n;
        return 0;
    }
};

struct List_002713D8 {
    int m0;
    int m4;
    int m8;
    Node_002713D8* m_first;
    int m10;
    int m14;

    Node_002713D8* First()
    {
        Node_002713D8* f = m_first;
        if ((int)f->m_data != -1)
            return f;
        return 0;
    }
};

struct Owner_002713D8 {
    int m_pad[7];
    List_002713D8 m_a;
    List_002713D8 m_b;
    void Clear();
};

void Owner_002713D8::Clear()
{
    List_002713D8* b = &m_b;
    Node_002713D8* n = m_a.First();
    while (n) {
        Node_002713D8* next = n->Next();
        delete n;
        n = next;
    }
    n = b->First();
    while (n) {
        Node_002713D8* next = n->Next();
        delete n;
        n = next;
    }
}
