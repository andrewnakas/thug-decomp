extern void* D_0038C7B0;
extern "C" int func_001896B0(void* mgr);
extern "C" void func_001891C8(void* mgr, void* t);

struct N_001874A8 {
    int m0;
    int m_data;
    int m_pri;
    N_001874A8* m_next;
    N_001874A8* m_prev;
};

struct C_001874A8;

struct T_001874A8 {
    char pad0[0x10];
    C_001874A8* m_owner;
    char pad14[0x18 - 0x14];
    unsigned int m_id;
    char pad1C[0x2C - 0x1C];
    N_001874A8 m_node;
    void SetId(int id);
};

struct C_001874A8 {
    int m0;
    N_001874A8 m_list;
    char pad18[0x20 - 0x18];
    unsigned int m20;
    void Add(T_001874A8* t);
};

void C_001874A8::Add(T_001874A8* t)
{
    void* mgr = D_0038C7B0;
    N_001874A8* node = &t->m_node;
    t->m_owner = this;
    N_001874A8* head = &m_list;
    N_001874A8* n = head->m_next;
    int pri = node->m_pri;
    for (;;) {
        N_001874A8* c = 0;
        if (n->m_data != -1) c = n;
        if (!c) break;
        if (pri >= c->m_pri) {
            N_001874A8* p = c->m_prev;
            node->m_next = c;
            node->m_prev = p;
            c->m_prev->m_next = node;
            c->m_prev = node;
            goto done;
        }
        n = c->m_next;
    }
    {
        N_001874A8* q = head->m_prev;
        node->m_next = head;
        node->m_prev = q;
    head->m_prev->m_next = node;
        head->m_prev = node;
    }
done:
    m20 = 0xFFFFFFFF;
    if (t->m_id == 0xFFFFFFFF) t->SetId(func_001896B0(mgr));
    func_001891C8(mgr, t);
}
