/* sym: _vt$11It_00104DB0 = 0x0035A9D0 */
struct Node_00104DB0 {
    int m0;
    int m_data;
    int m8;
    Node_00104DB0* m_prev;
    Node_00104DB0* m_next;
    Node_00104DB0* Valid()
    {
        if (m_data == -1) {
            return 0;
        }
        return this;
    }
    int GetData() { return m_data; }
};

class It_00104DB0 {
public:
    int m0;
    Node_00104DB0* m_cur;
    It_00104DB0() { m_cur = 0; }
    virtual ~It_00104DB0() {}
    virtual void Run();
    int Next()
    {
        m_cur = m_cur->m_prev->Valid();
        if (!m_cur) {
            return 0;
        }
        return m_cur->GetData();
    }
    int First(Node_00104DB0* h)
    {
        m_cur = h;
        return Next();
    }
};

extern "C" void func_00104E90(int obj, int flags);

struct Owner_00104DB0 {
    char pad[0x24];
    Node_00104DB0 m_head;
    void DeleteAll();
};

void Owner_00104DB0::DeleteAll()
{
    It_00104DB0 it;
    int d;
    while ((d = it.First(&m_head)) != 0) {
        func_00104E90(d, 3);
    }
}
