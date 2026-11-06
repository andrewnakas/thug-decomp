struct Node_001706A8 {
    char pad0[0x1C];
    unsigned int m1C;
    Node_001706A8* m20;
    int m24;
    Node_001706A8* m28;
    void AddChild(Node_001706A8* c);
    static Node_001706A8* Last(Node_001706A8* p)
    {
        while (p->m28)
            p = p->m28;
        return p;
    }
};

void Node_001706A8::AddChild(Node_001706A8* c)
{
    if (m1C & 2) {
        m20 = c;
    } else {
        Node_001706A8* p = m20;
        if (p)
            Last(p)->m28 = c;
        else
            m20 = c;
    }
    m1C &= ~2;
}
