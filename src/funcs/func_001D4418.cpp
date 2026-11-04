extern "C" void* func_001046B0(int size);

struct Link_001D4418 {
    int m0;
    int m_value;
    int m8;
    Link_001D4418* m_next;
    Link_001D4418* m_prev;
    Link_001D4418(int v)
    {
        m_value = v;
        m_next = this;
        m_prev = this;
        m8 = 0;
    }
    void InsertBefore(Link_001D4418* where)
    {
        m_prev = where->m_prev;
        m_next = where;
        where->m_prev->m_next = this;
        where->m_prev = this;
    }
    virtual void Release();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct List_001D4418 {
    char m_pad[0x10];
    Link_001D4418* m_head;
    void Add(int v);
};

void List_001D4418::Add(int v)
{
    Link_001D4418* node = new Link_001D4418(v);
    node->InsertBefore(m_head);
}
