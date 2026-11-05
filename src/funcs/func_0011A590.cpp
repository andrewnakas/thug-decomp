class Node_0011A590 {
public:
    int m0;
    int m_data;
    int m8;
    Node_0011A590* m_prev;
    Node_0011A590* m_next;
    virtual ~Node_0011A590();
    Node_0011A590* Valid()
    {
        return m_data != -1 ? this : 0;
    }
};

struct Obj_0011A590 {
    char pad[0x70];
    Node_0011A590* m_head;
    void DeleteAll();
};

void Obj_0011A590::DeleteAll()
{
    Node_0011A590* n = m_head->Valid();
    while (n) {
        Node_0011A590* next = n->m_prev->Valid();
        delete n;
        n = next;
    }
}
