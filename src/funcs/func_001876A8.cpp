class Owner_001876A8 {
public:
    int m0;
    int m4;
    virtual ~Owner_001876A8();
};

struct Link_001876A8 {
    int m0;
    Owner_001876A8* m_owner;
    int m8;
    Link_001876A8* m_next;
    Link_001876A8* m_prev;

    Link_001876A8* Valid()
    {
        if (~(int)m_owner == 0) return 0;
        return this;
    }
    void Unlink()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

class Obj_001876A8 {
public:
    char pad0[0x30];
    Link_001876A8 m_list;

    void DeleteAll();
};

void Obj_001876A8::DeleteAll()
{
    Link_001876A8* n = m_list.m_next->Valid();
    while (n) {
        Link_001876A8* cur = n;
        n = cur->m_next->Valid();
        cur->Unlink();
        if (cur->m_owner) {
            delete cur->m_owner;
        }
    }
}
