/* force: {"kind": "ga", "before": [120, 158]} */
/* near miss: 8 words: n/i callee-saved regs swapped (game n=$s0, i+1=$s1). */
struct Node_00265250 {
    int m_pad0;
    void* m_data;
    int m_pad8;
    Node_00265250* m_next;
};

struct List_00265250 {
    int m_pad[3];
    Node_00265250* m_next;
};

struct Skate_00265250 {
    char m_pad[0x3B0];
    unsigned int m_mode;
};

extern Skate_00265250* D_0038FC78;

static inline Node_00265250* Valid_00265250(Node_00265250* n)
{
    if (~(int)n->m_data)
        return n;
    return 0;
}

static inline Node_00265250* Next_00265250(Node_00265250* n)
{
    Node_00265250* p = n->m_next;
    return ~(int)p->m_data ? p : 0;
}

static inline Node_00265250* First_00265250(List_00265250* l)
{
    if (!~(int)l->m_next->m_data)
        return 0;
    return l->m_next;
}

static inline Node_00265250* GetItem_00265250(List_00265250* l, unsigned int idx)
{
    Node_00265250* p = First_00265250(l);
    while (p) {
        if (idx-- == 0)
            return p;
        p = Next_00265250(p);
    }
    return 0;
}

static inline unsigned int Count_00265250(List_00265250* l)
{
    unsigned int n = 0;
    for (Node_00265250* p = Valid_00265250(l->m_next); p; p = Valid_00265250(p->m_next))
        n++;
    return n;
}

struct Mgr_00265250 {
    char m_pad[0x18];
    int m_18;
    char m_pad1C[0x28 - 0x1C];
    List_00265250 m_list;
    bool Write(void* out);
};

extern "C" void func_00264E38(void* data, void* out);
extern "C" void* func_0029C320();
extern "C" void func_0029C0F0(void* p, int a, void* out);

bool Mgr_00265250::Write(void* out)
{
    unsigned int n = Count_00265250(&m_list);
    for (unsigned int i = 0; i < n; i++)
        func_00264E38(GetItem_00265250(&m_list, i)->m_data, out);
    unsigned int mode = D_0038FC78->m_mode;
    if (mode == 0xB664035D)
        func_0029C0F0(func_0029C320(), m_18, out);
    return true;
}
