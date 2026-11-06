/* fuzzy: 95.5 */
typedef int qword_001D4648 __attribute__((mode(TI)));

extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void* func_001046B0(unsigned int size);
extern char D_003642D0[];
extern char D_00364230[];
extern char D_00363EC0[];
extern char D_00363ED8[];

struct Node_001D4648 {
    int m0;
    void* m_data;
    int m8;
    Node_001D4648* m_next;
    Node_001D4648* m_prev;
    void* m_vt;
};

struct VtSlot_001D4648 {
    short delta;
    short pad;
    void* (*fn)(void*, int);
};

struct Obj_001D4648 {
    int m0;
    unsigned short m4;
    int m8;
    VtSlot_001D4648* m_vt;
    Node_001D4648* m_list;
    int pad14[3];
    qword_001D4648 m20;
    qword_001D4648 m30;
    int m40;
    int m44;
    int m48;
};

static inline void Insert_001D4648(Node_001D4648* n, Node_001D4648* h)
{
    n->m_prev = h->m_prev;
    n->m_next = h;
    h->m_prev->m_next = n;
    h->m_prev = n;
}

static inline void InitNode_001D4648(Node_001D4648* n, void* c, void* vt)
{
        n->m_next = n;
        n->m_prev = n;
        n->m_data = c;
        n->m_vt = vt;
        n->m8 = 0;
}

static inline Node_001D4648* Valid_001D4648(Node_001D4648* n)
{
    Node_001D4648* r = 0;
    if (n->m_data != (void*)-1)
        r = n;
    return r;
}

Obj_001D4648* func_001D4648(Obj_001D4648* src, int arg)
{
    Obj_001D4648* p = (Obj_001D4648*)func_0010A638(D_00388A70, 0x50, 1, 0);
    p->m_vt = (VtSlot_001D4648*)D_003642D0;
    p->m0 = src->m0;
    p->m4 = src->m4;
    p->m8 = src->m8;
    p->m_vt = (VtSlot_001D4648*)D_00364230;
    p->m_list = src->m_list;
    p->m20 = src->m20;
    p->m30 = src->m30;
    p->m40 = src->m40;
    p->m44 = src->m44;
    p->m48 = src->m48;
    p->m4 |= 0x8000;

    Node_001D4648* head = (Node_001D4648*)func_001046B0(0x18);
    head->m_data = (void*)-1;
    head->m_vt = D_00363EC0;
    head->m8 = 0;
    head->m_next = head;
    head->m_prev = head;
    p->m_list = head;

    void* nvt = D_00363ED8;
    Node_001D4648* it = Valid_001D4648(src->m_list->m_next);
    if (it) do {
        Node_001D4648* n = (Node_001D4648*)func_001046B0(0x18);
        Obj_001D4648* o = (Obj_001D4648*)it->m_data;
        VtSlot_001D4648* s = (VtSlot_001D4648*)((char*)o->m_vt + 0x68);
        void* c = s->fn((char*)o + s->delta, arg);
        InitNode_001D4648(n, c, nvt);
        Insert_001D4648(n, p->m_list);
        it = Valid_001D4648(it->m_next);
    } while (it);
    return p;
}
