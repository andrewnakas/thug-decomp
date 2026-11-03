struct Node_00265528 {
    int m_pad0;
    void* m_data;
    int m_pad8;
    Node_00265528* m_next;
};

struct List_00265528 {
    int m_pad[3];
    Node_00265528* m_next;
};

struct Skate_00265528 {
    char m_pad[0x3B0];
    unsigned int m_mode;
};

extern Skate_00265528* D_0038FC78;

static inline Node_00265528* Valid_00265528(Node_00265528* n)
{
    if (~(int)n->m_data)
        return n;
    return 0;
}

static inline Node_00265528* Next_00265528(Node_00265528* n)
{
    Node_00265528* p = n->m_next;
    return ~(int)p->m_data ? p : 0;
}

static inline Node_00265528* First_00265528(List_00265528* l)
{
    if (!~(int)l->m_next->m_data)
        return 0;
    return l->m_next;
}

static inline Node_00265528* GetItem_00265528(List_00265528* l, unsigned int idx)
{
    Node_00265528* p = First_00265528(l);
    while (p) {
        if (idx-- == 0)
            return p;
        p = Next_00265528(p);
    }
    return 0;
}

static inline unsigned int Count_00265528(List_00265528* l)
{
    unsigned int n = 0;
    Node_00265528* p = First_00265528(l);
    while (p) {
        p = Next_00265528(p);
        n++;
    }
    return n;
}

struct Mgr_00265528 {
    char m_pad[0x18];
    int m_18;
    char m_pad1C[0x28 - 0x1C];
    List_00265528 m_list;
    bool Read(void* in);
};

extern "C" int func_00264EE8(void* data, void* in);
extern "C" void* func_0029C320();
extern "C" void func_0029C128(void* p, int a);

bool Mgr_00265528::Read(void* in)
{
    unsigned int n = Count_00265528(&m_list);
    for (unsigned int i = 0; i < n; i++) {
        if (!func_00264EE8(GetItem_00265528(&m_list, i)->m_data, in))
            return false;
    }
    unsigned int mode = D_0038FC78->m_mode;
    if (mode == 0xB664035D)
        func_0029C128(func_0029C320(), m_18);
    return true;
}
