struct Node_001A2728 {
    int m0;
    int m_tag;
    int m8;
    Node_001A2728* m_next;
    Node_001A2728* m_prev;
    virtual ~Node_001A2728();
};

static inline Node_001A2728* Valid_001A2728(Node_001A2728* n)
{
    Node_001A2728* r = 0;
    if (n->m_tag != -1) r = n;
    return r;
}

struct Obj_001A2728 {
    char pad0[0x28];
    Node_001A2728* m28;
    void Clear();
};

void Obj_001A2728::Clear()
{
    Node_001A2728* n = Valid_001A2728(m28);
    while (n) {
        Node_001A2728* next = Valid_001A2728(n->m_next);
        delete n;
        n = next;
    }
}
