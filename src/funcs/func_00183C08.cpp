/* sym: _vt$13List_00183C08 = 0x003618C8 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class List_00183C08;

struct Node_00183C08 {
    List_00183C08* m_list;
    Node_00183C08* m_prev;
    Node_00183C08* m_next;
};

extern "C" void func_00183CB8(List_00183C08* list, Node_00183C08* n);

static inline void Detach(Node_00183C08* n)
{
    if (n->m_list) {
        func_00183CB8(n->m_list, n);
        n->m_list = 0;
    }
}

class List_00183C08 {
public:
    int m0;
    Node_00183C08* m_head;

    virtual void Key();
    virtual ~List_00183C08();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

List_00183C08::~List_00183C08()
{
    Node_00183C08* n = m_head;
    while (n) {
        Node_00183C08* next = n->m_next;
        Detach(n);
        n->m_list = 0;
        n = next;
    }
}
