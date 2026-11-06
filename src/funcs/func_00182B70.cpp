/* sym: _vt$13Link_00182B70 = 0x00361818 */
/* sym: _vt$13Node_00182B70 = 0x003617C0 */
/* sym: _vt$13Task_00182B70 = 0x00361830 */
/* sym: __13Base_00182B70i = 0x001047F8 */

extern "C" void* func_001046B0(int size);
extern "C" void func_00182CA0(void* owner);

class Node_00182B70 {
public:
    int m0;
    unsigned int m_id;
    int m8;
    Node_00182B70* m_prev;
    Node_00182B70* m_next;

    Node_00182B70(unsigned int id)
    {
        m_id = id;
        m8 = 0;
        m_prev = this;
        m_next = this;
    }
    virtual ~Node_00182B70();
};

class Link_00182B70 : public Node_00182B70 {
public:
    Link_00182B70() : Node_00182B70(0xFFFFFFFF) {}
    virtual ~Link_00182B70();
};

class Base_00182B70 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;

    Base_00182B70(int pri);
    virtual ~Base_00182B70();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Task_00182B70 : public Base_00182B70 {
public:
    void (*m_func)(void*);
    void* m_owner;

    Task_00182B70(void* owner, void (*func)(void*)) : Base_00182B70(-1000)
    {
        m_func = func;
        m_owner = owner;
    }
    virtual ~Task_00182B70();
};

class Mgr_00182B70 {
public:
    int m0;
    Task_00182B70* m_task;
    Link_00182B70 m_link;
    int m20;

    Mgr_00182B70();
};

Mgr_00182B70::Mgr_00182B70()
{
    m_task = new Task_00182B70(this, func_00182CA0);
    m20 = 0;
}
