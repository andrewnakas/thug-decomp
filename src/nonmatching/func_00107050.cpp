/* fuzzy: 97.8 */
/* sym: _vt$11It_00107050 = 0x0035AE38 */
/* sym: _vt$13List_00107050 = 0x0035AE80 */
/* sym: _vt$12Mgr_00107050 = 0x0035AE50 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_0031A0E8();
extern void* D_00388A70;

struct Node_00107050 {
    int m0;
    void* m4;
    int m8;
    Node_00107050* mC;
    Node_00107050* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

class It_00107050 {
public:
    int m0;
    Node_00107050* cur;
    It_00107050() {}
    virtual ~It_00107050() {}
    virtual void Run();
    void* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* Advance(Node_00107050* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* First(Node_00107050* h)
    {
        cur = h;
        return Next();
    }
};

/* List head: an always-invalid node (m4 = -1) linking the entries in a ring. */
class List_00107050 {
public:
    int m0;
    int m4;
    int m8;
    List_00107050* m_next;
    List_00107050* m_prev;
    virtual ~List_00107050()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
    virtual void Run();
};

/* The entries (streams) owned by the manager; vptr at 0xEC, slot 0 is the deleting destructor. */
class Item_00107050 {
public:
    char pad[0xEC];
    virtual ~Item_00107050();
};

class Task_00107050 {
public:
    char pad[0x18];
    virtual void Run();
    virtual void Stop();
    virtual ~Task_00107050();
};

class Mgr_00107050 {
public:
    int m0;
    List_00107050 m_list;
    Task_00107050* m_task;
    virtual void Update();
    virtual ~Mgr_00107050();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Mgr_00107050::~Mgr_00107050()
{
    It_00107050 it;
    Item_00107050* item = (Item_00107050*)it.First((Node_00107050*)&m_list);
    It_00107050* p = &it;
    while (item) {
        Item_00107050* next = (Item_00107050*)p->Advance(it.cur);
        delete item;
        item = next;
    }
    delete m_task;
    func_0031A0E8();
}
