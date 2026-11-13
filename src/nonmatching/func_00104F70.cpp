/* fuzzy: 79.5 */
/* sym: _vt$13Node_00104F70 = 0x0035AA00 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Node_00104F70 {
public:
    int m0;
    int m_data;
    int m8;
    Node_00104F70* m_prev;
    Node_00104F70* m_next;
    virtual void Run();
    virtual ~Node_00104F70()
    {
        m_next->m_prev = m_prev;
        m_prev->m_next = m_next;
        m_prev = this;
        m_next = this;
    }
    Node_00104F70* Valid()
    {
        if (m_data == -1) {
            return 0;
        }
        return this;
    }
    int Count()
    {
        int c = 0;
        Node_00104F70* p = m_prev;
        Node_00104F70* n;
        while ((n = p->Valid()) != 0) {
            c++;
            p = n->m_prev;
        }
        return c;
    }
};

class Mgr_00104F70;
extern "C" void func_001050D8(Mgr_00104F70* self);
extern "C" void func_00104DB0(Mgr_00104F70* self);

class Mgr_00104F70 {
public:
    int m0;
    int m4;
    int m8;
    Node_00104F70 m_list0;
    Node_00104F70 m_list1;
    ~Mgr_00104F70();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Mgr_00104F70::~Mgr_00104F70()
{
    while (m_list0.Count() != 0) {
        func_001050D8(this);
    }
    func_00104DB0(this);
}
