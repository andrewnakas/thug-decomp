/* fuzzy: 84.6 */
struct Node_0011A7A0 {
    int m0;
    unsigned int m_id;
    int m8;
    Node_0011A7A0* m_next;
    Node_0011A7A0* Valid()
    {
        if (m_id == 0xFFFFFFFF) {
            return 0;
        }
        return this;
    }
    Node_0011A7A0* Next() { return m_next->Valid(); }
};

extern "C" void func_00118348(Node_0011A7A0* n, int on);

struct List_0011A7A0 {
    int m0;
    unsigned int m_id;
    int m8;
    Node_0011A7A0* m_first;
    Node_0011A7A0* First()
    {
        Node_0011A7A0* p = m_first;
        if (p->m_id == 0xFFFFFFFF) {
            p = 0;
        }
        return p;
    }
    int Count()
    {
        int n = 0;
        for (Node_0011A7A0* p = First(); p; p = p->Next()) {
            n++;
        }
        return n;
    }
    Node_0011A7A0* Nth(unsigned int i)
    {
        Node_0011A7A0* p = m_first;
        if (p->m_id == 0xFFFFFFFF) p = 0;
        for (; p; p = p->Next()) {
            if (i-- == 0) return p;
        }
        return 0;
    }
};

class Track_0011A7A0 {
public:
    char pad0[0x64];
    List_0011A7A0 m_events;
    void EnableAll();
};

void Track_0011A7A0::EnableAll()
{
    int i;
    int n = m_events.Count();
    for (i = 0; i < n; i++) {
        func_00118348(m_events.Nth(i), 1);
    }
}
