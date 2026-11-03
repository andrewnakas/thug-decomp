extern "C" void* func_001046B0(int size);

struct Node_001D33D8 {
    int m0;
    unsigned short m_flags;
    short m6;
    void* m8;
    Node_001D33D8();
    virtual void Update();
    virtual ~Node_001D33D8();
};

struct Sub_001022D8 {
    int m_data[8];
    Sub_001022D8();
};

struct Head_001D4298 {
    int m0;
    unsigned int m_value;
    int m8;
    Head_001D4298* m_next;
    Head_001D4298* m_prev;
    Head_001D4298()
    {
        m_value = 0xFFFFFFFF;
        m8 = 0;
        m_next = this;
        m_prev = this;
    }
    virtual void Release();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct List_001D4298 : Node_001D33D8 {
    Head_001D4298* m_head;
    int m_pad[3];
    Sub_001022D8 m_20;
    int m_40;
    int m_44;
    int m_48;
    List_001D4298();
    virtual void Update();
};

List_001D4298::List_001D4298()
{
    m_head = new Head_001D4298;
    m_40 = 1;
    m_48 = 0;
}
