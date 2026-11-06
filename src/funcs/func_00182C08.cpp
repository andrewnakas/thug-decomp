/* sym: _vt$13Node_00182C08 = 0x003617C0 */
/* sym: _vt$13Link_00182C08 = 0x00361818 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_00182EB0(void* mgr);

class Node_00182C08 {
public:
    int m0;
    unsigned int m_id;
    int m8;
    Node_00182C08* m_prev;
    Node_00182C08* m_next;

    virtual void Key();
    virtual ~Node_00182C08()
    {
        m_next->m_prev = m_prev;
        m_prev->m_next = m_next;
        m_prev = this;
        m_next = this;
    }
};

class Link_00182C08 : public Node_00182C08 {
public:
    virtual void Key();
    virtual ~Link_00182C08() {}
};

class Task_00182C08 {
public:
    char pad[0x18];
    virtual void V1();
    virtual void V2();
    virtual ~Task_00182C08();
};

class Mgr_00182C08 {
public:
    int m0;
    Task_00182C08* m_task;
    Link_00182C08 m_link;
    int m20;

    ~Mgr_00182C08();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Mgr_00182C08::~Mgr_00182C08()
{
    func_00182EB0(this);
    delete m_task;
}
