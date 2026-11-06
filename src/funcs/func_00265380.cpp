/* sym: __13Node_00265380Pv = 0x00264DB0 */
extern "C" void* func_001046B0(int size);

struct Link_00265380 {
    int m0;
    int m4;
    int m8;
    Link_00265380* m_next;
    Link_00265380* m_prev;
    virtual ~Link_00265380();
};

struct Node_00265380 : Link_00265380 {
    int m18;
    Node_00265380(void* data);
    bool Init(void* data);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

extern "C" bool func_00264DD8(Node_00265380* n, void* data);

struct List_00265380 {
    char pad[0x28];
    Link_00265380 m_head;
    bool Add(void* data);
};

bool List_00265380::Add(void* data)
{
    Node_00265380* n = new Node_00265380(data);
    if (!n)
        return false;
    if (func_00264DD8(n, data)) {
        Link_00265380* head = &m_head;
        n->m_prev = head->m_prev;
        n->m_next = head;
        head->m_prev->m_next = n;
        head->m_prev = n;
        return true;
    }
    delete n;
    return false;
}
