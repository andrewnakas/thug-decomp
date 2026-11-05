/* sym: _vt$11It_00104C70 = 0x0035A988 */
struct Node_00104C70 {
    int m0;
    int m_data;
    int m8;
    Node_00104C70* m_prev;
    Node_00104C70* m_next;
    void* m_vtbl;
    Node_00104C70* Valid()
    {
        if (m_data == -1) {
            return 0;
        }
        return this;
    }
    int GetData() { return m_data; }
};

class It_00104C70 {
public:
    int m0;
    Node_00104C70* m_cur;
    It_00104C70() { m_cur = 0; }
    virtual ~It_00104C70() {}
    virtual void Run();
    int Next()
    {
        m_cur = m_cur->m_prev->Valid();
        if (!m_cur) {
            return 0;
        }
        return m_cur->GetData();
    }
    int First(Node_00104C70* h)
    {
        m_cur = h;
        return Next();
    }
};

extern "C" void func_001048F0(int task);

struct List_00104C70 {
    int m0;
    int m_refs;
    Node_00104C70 m_head;
    int m20;
    int m_dirty;
    void RemoveAll();
};

void List_00104C70::RemoveAll()
{
    It_00104C70 it;
    m_refs++;
    int d;
    while ((d = it.First(&m_head)) != 0) {
        func_001048F0(d);
        m_dirty = 1;
    }
    m_refs--;
}
