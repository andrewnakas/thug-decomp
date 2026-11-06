/* sym: _$_13Conn_00200F28 = 0x00201A68 */

struct Link_00200F28 {
    char pad0[0xC];
    Link_00200F28* m_prev;
    Link_00200F28* m_next;
    void Remove()
    {
        m_next->m_prev = m_prev;
        m_prev->m_next = m_next;
        m_prev = this;
        m_next = this;
    }
};

class Conn_00200F28 {
public:
    char pad0[0x4910];
    Link_00200F28 m_link;
    ~Conn_00200F28();
};

struct Mgr_00200F28;

extern "C" void func_00200F28(Mgr_00200F28* mgr, Conn_00200F28* c)
{
    c->m_link.Remove();
    delete c;
}
