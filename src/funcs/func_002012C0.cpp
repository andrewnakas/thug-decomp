extern char D_00366C08[];
extern "C" void* func_001046B0(int size);

struct Node_002012C0 {
    int m0;
    void* m_data;
    int m8;
    Node_002012C0* m_next;
    Node_002012C0* m_prev;
    void* m_vt;
    int m_id;
    void InsertBefore(Node_002012C0* n)
    {
        n->m_prev = m_prev;
        n->m_next = this;
        m_prev->m_next = n;
        m_prev = n;
    }
};

struct Key_002012C0 {
    char pad[0x4C];
    int m4C;
};

struct Obj_002012C0 {
    char pad[0x42F0];
    Node_002012C0 m_list;
    void Add(Key_002012C0* k);
};

void Obj_002012C0::Add(Key_002012C0* k)
{
    Node_002012C0* n = (Node_002012C0*)func_001046B0(0x1C);
    n->m_next = n;
    n->m_prev = n;
    n->m_vt = D_00366C08;
    n->m_data = n;
    n->m8 = 0;
    n->m_id = k->m4C;
    m_list.InsertBefore(n);
}
