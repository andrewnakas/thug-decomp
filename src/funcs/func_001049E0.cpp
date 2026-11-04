extern char D_0035A9A0[];

struct LinkNode1049E0 {
    int m0;
    unsigned int m4;
    int m8;
    LinkNode1049E0* m_prev;
    LinkNode1049E0* m_next;
    void* m_vtbl;

    LinkNode1049E0()
    {
        m4 = 0xFFFFFFFF;
        m8 = 0;
        m_prev = this;
        m_next = this;
        m_vtbl = D_0035A9A0;
    }
};

struct Obj1049E0 {
    int m0;
    int m4;
    LinkNode1049E0 m_node;
    int m20;
    int m24;
    Obj1049E0();
};

Obj1049E0::Obj1049E0() : m4(0)
{
    m20 = 0;
    m24 = 0;
}
