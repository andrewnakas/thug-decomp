class Link_00189F18 {
public:
    int m0;
    void* m_item;
    int m8;
    Link_00189F18* m_next;
    Link_00189F18* m_prev;

    virtual ~Link_00189F18();

    Link_00189F18* Valid()
    {
        if (~(int)m_item == 0) return 0;
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

class Entry_00189F18 {
public:
    int m0;
    Link_00189F18 m_list;

    void Remove(void* item);
};

void Entry_00189F18::Remove(void* item)
{
    Link_00189F18* found = 0;
    for (Link_00189F18* n = m_list.m_next->Valid(); n; n = n->m_next->Valid()) {
        if (n->m_item == item) {
            found = n;
            break;
        }
    }
    if (found) {
        found->Unlink();
        delete found;
    }
}
