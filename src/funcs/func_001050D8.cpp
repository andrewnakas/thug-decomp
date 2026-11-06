/* sym: _vt$11It_001050D8 = 0x0035A9D0 */

struct LNode_001050D8 {
    int m0;
    void* m_data;
    int m8;
    LNode_001050D8* m_next;
    LNode_001050D8* m_prev;
    LNode_001050D8* Valid(unsigned int k = 0) { return k < ~(unsigned int)m_data ? this : 0; }
    void* GetData() { return m_data; }
    void Remove()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
    void AddToHead(LNode_001050D8* n)
    {
        n->m_prev = this;
        n->m_next = m_next;
        m_next->m_prev = n;
        m_next = n;
    }
};

struct Task_001050D8 {
    char pad[0x28];
    LNode_001050D8* node;
};

extern "C" void func_00104E90(Task_001050D8* t, int a);

class It_001050D8 {
public:
    int m0;
    LNode_001050D8* m_cur;
    It_001050D8() { m_cur = 0; }
    virtual ~It_001050D8() {}
    virtual void Run();
    void* Next()
    {
        m_cur = m_cur->m_next->Valid();
        if (!m_cur) {
            return 0;
        }
        return m_cur->GetData();
    }
    void* First(LNode_001050D8* h)
    {
        m_cur = h;
        return Next();
    }
};

struct Mgr_001050D8 {
    int m0;
    int m4;
    int m8;
    LNode_001050D8 head;
    int m20;
    LNode_001050D8 list2;
    int m38;
    Task_001050D8* m3C;
    Task_001050D8* m40;
    int m44;
    int m48;
    void Step();
};

void Mgr_001050D8::Step()
{
    It_001050D8 it;
    it.First(&head);
    if (m40 == m3C) {
        m40 = (Task_001050D8*)it.Next();
    } else {
        m44 = 0;
    }
    if (m4 == 0) {
        if (m3C) {
            func_00104E90(m3C, 3);
        }
    } else {
        m3C->node->Remove();
        list2.AddToHead(m3C->node);
    }
    m3C = m40;
    m48 = 1;
}
