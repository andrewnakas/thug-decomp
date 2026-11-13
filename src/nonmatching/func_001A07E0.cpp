/* fuzzy: 93.6 */
struct Node_001A07E0 {
    int m0;
    int m_tag;
    int m8;
    Node_001A07E0* m_next;
    Node_001A07E0* m_prev;
    virtual ~Node_001A07E0();
    Node_001A07E0* First();
    int Count();
    Node_001A07E0* Trim(int max);
    void Insert(Node_001A07E0* nn)
    {
        nn->m_prev = this;
        nn->m_next = m_next;
        m_next->m_prev = nn;
        m_next = nn;
    }

    void Remove()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

static inline Node_001A07E0* Valid_001A07E0(Node_001A07E0* n)
{
    Node_001A07E0* r = 0;
    if (n->m_tag != -1) r = n;
    return r;
}

inline Node_001A07E0* Node_001A07E0::First()
{
    return Valid_001A07E0(m_next);
}

static inline Node_001A07E0* Next_001A07E0(Node_001A07E0* n)
{
    Node_001A07E0* r = n->m_next;
    if (r->m_tag == -1) r = 0;
    return r;
}

inline int Node_001A07E0::Count()
{
    int cnt = 0;
    for (Node_001A07E0* n = Next_001A07E0(this); n; n = Next_001A07E0(n))
        cnt++;
    return cnt;
}

inline Node_001A07E0* Node_001A07E0::Trim(int max)
{
    int i = 0;
    Node_001A07E0* n = First();
    while (n) {
        Node_001A07E0* next = Valid_001A07E0(n->m_next);
        if (++i >= max) {
            n->Remove();
            delete n;
        }
        n = next;
    }
    return this;
}

struct Part_001A07E0 {
    int m0;
    int m_tag;
    int m8;
    Part_001A07E0* m_next;
    char pad10[0x54 - 0x10];
    float m54;
    float m58;
};

static inline Part_001A07E0* Valid_001A07E0(Part_001A07E0* n)
{
    Part_001A07E0* r = 0;
    if (n->m_tag != -1) r = n;
    return r;
}

extern "C" void* func_001046B0(int size);
extern "C" Node_001A07E0* func_00119978(void* mem, int a);
extern "C" int func_0011A080(Part_001A07E0* p, float f);
extern "C" int func_0011A240(Part_001A07E0* p);

struct A_001A07E0 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m_pad[3];
};

struct C_001A07E0 : A_001A07E0 {
    Node_001A07E0 m_head;
    void Fn(float f);
};

extern "C" Part_001A07E0* func_001A0718(C_001A07E0* self);

void C_001A07E0::Fn(float f)
{
    Node_001A07E0* head = m_head.Trim(3);
    Part_001A07E0* part = head->Count() ? func_001A0718(this) : 0;
    if (part && func_0011A080(part, f)) {
        float sum = 0.0f;
        for (Part_001A07E0* q = Valid_001A07E0(part->m_next); q; q = Valid_001A07E0(q->m_next)) {
            if (func_0011A240(q)) sum += q->m54 * q->m58;
        }
        part->m58 = (1.0f - sum) / part->m54;
    }
    Node_001A07E0* nn = func_00119978(func_001046B0(0x7C), mC);
    head->Insert(nn);
}
