struct Node_001D0FC8 {
    int m0;
    int m4;
    int m8;
    unsigned char m_kind;
    char m_padC[3];
    int m10;
    int m_pad[3];
    Node_001D0FC8();
    virtual ~Node_001D0FC8() = 0;
    virtual void Update();
};

struct Ref_001D1AD0;

struct Owner_001D1AD0 {
    int m0;
    int m4;
    int m8;
    unsigned char m_kind;
    char m_padC[3];
    int m10;
    Ref_001D1AD0* m_head;
};

struct Ref_001D1AD0 : Node_001D0FC8 {
    Owner_001D1AD0* m_owner;
    Ref_001D1AD0* m_next;
    Ref_001D1AD0(Owner_001D1AD0* owner);
    virtual void Update();
    virtual ~Ref_001D1AD0();
};

Ref_001D1AD0::~Ref_001D1AD0()
{
    if (m_owner) {
        Ref_001D1AD0* p = m_owner->m_head;
        if (p == this) {
            m_owner->m_head = m_next;
        } else {
            while (p && p->m_next != this) {
                p = p->m_next;
            }
            p->m_next = m_next;
        }
        m_owner = 0;
        m_next = 0;
    }
}
