/* fuzzy: 84.6 */
struct Obj_0012DE78;
struct Handle_0012DE78;

extern "C" void func_00183C98(Obj_0012DE78* o, Handle_0012DE78* h);
extern "C" void func_00183CB8(Obj_0012DE78* o, Handle_0012DE78* h);

struct Obj_0012DE78 {
    char pad[0x18];
    int m18;
};

struct Handle_0012DE78 {
    Obj_0012DE78* m_obj;
    Handle_0012DE78* m_prev;
    Handle_0012DE78* m_next;
    Handle_0012DE78(const Handle_0012DE78& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012DE78()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Obj_0012DE78* operator->() const { return m_obj; }
    operator Obj_0012DE78*() const { return m_obj; }
};

static inline Handle_0012DE78 Make_0012DE78(const Handle_0012DE78& t)
{
    return t;
}

struct Node_0012DE78 {
    Obj_0012DE78* m_obj;
    char pad4[0xC];
    Node_0012DE78* m_next;
    int m_tried;
    int m_skip;
};

struct Event_0012DE78 {
    unsigned int m_type;
    int m4;
    unsigned int m_target;
    int mC;
    void* m_params;
};

struct Skater_0012DE78 {
    char pad0[0x3AC];
    unsigned int m3AC;
    char pad3B0[0x444 - 0x3B0];
    int m444;
};

struct Arr_0012DE78 {
    char pad0[0xC];
    int m_size;
};

extern char D_0035D268[];
extern Skater_0012DE78* D_0038FC78;
extern void* D_0038C7B0;
extern "C" Arr_0012DE78* func_001E55F8(const char* name, int required);
extern "C" unsigned int func_001E9300(Arr_0012DE78* a, int index);
extern "C" bool func_0022EF38(Skater_0012DE78* s);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" bool func_00125DC8(Obj_0012DE78* o);
extern "C" int func_00187D68(Event_0012DE78* e);
extern "C" void func_00187CE8(Event_0012DE78* e, int a, int b);
extern "C" void func_00187D28(Event_0012DE78* e, int a, int b);
extern "C" bool func_00189750(void* mgr, unsigned int type, int target, int id, void* params, int a);

struct C_0012E438 {
    char pad0[0x5A4];
    Node_0012DE78* m_lists[2];
    int m_restart[2];
    unsigned int m_names[(0x674 - 0x5B4) / 4];
    int m_numNames;
    Handle_0012DE78 Find(int id, int flag);
    void Add(Handle_0012DE78* h, int list);
    void Remove(Handle_0012DE78* h, int parents, int mark);
    void Unmark(Handle_0012DE78* h);
    bool IsFocusEvent(unsigned int type);
    void Visit(Node_0012DE78* n);
    void HandleEvent(Event_0012DE78* ev);
};

void C_0012E438::HandleEvent(Event_0012DE78* ev)
{
    if (!m_numNames) {
        Arr_0012DE78* a = func_001E55F8(D_0035D268, 1);
        m_numNames = a->m_size;
        for (int i = 0; i < m_numNames; i++)
            m_names[i] = func_001E9300(a, i);
    }
    Skater_0012DE78* sk = D_0038FC78;
    if (!func_0022EF38(sk) && sk->m3AC != 0x9F2BAFB7) {
        Handle_0012DE78 h = Make_0012DE78(Find(0x021F1F4A, 0));
        if (!h) {
            int v;
            if (ev->m_params && func_001E7DE8(ev->m_params, 0xC9428A08, &v, 0) && sk->m444 != v)
                return;
        }
    }
    void* mgr = D_0038C7B0;
    if (ev->m_type == 0x9D3FB516 && ev->m_target != 0x36B2EE74) {
        Handle_0012DE78 h = Make_0012DE78(Find(ev->m_target, 0));
        if (h && !func_00125DC8(h)) {
            Add(&h, func_00187D68(ev));
            func_00187CE8(ev, 1, 0);
        }
    }
    if (ev->m_type == 0x4ADF0CD3 && ev->m_target != 0x36B2EE74) {
        Handle_0012DE78 h = Make_0012DE78(Find(ev->m_target, 0));
        if (h && !func_00125DC8(h)) {
            Remove(&h, 0, 0);
            func_00187CE8(ev, 1, 0);
        }
    }
    if (ev->m_type == 0x4A57316B) {
        Handle_0012DE78 h = Make_0012DE78(Find(ev->m_target, 0));
        Remove(&h, 1, 1);
        func_00187CE8(ev, 1, 0);
    }
    if (ev->m_type == 0x3056434F) {
        Handle_0012DE78 h = Make_0012DE78(Find(ev->m_target, 0));
        Unmark(&h);
        func_00187CE8(ev, 1, 0);
    }
    if (IsFocusEvent(ev->m_type) && ev->m_target == 0x36B2EE74) {
        int found = 0;
        int idx = func_00187D68(ev);
        Node_0012DE78* n;
        for (n = m_lists[idx]; n; n = n->m_next)
            n->m_tried = 0;
        m_restart[idx] = 1;
    restart:
        m_restart[idx] = 0;
        n = m_lists[idx];
        if (n) {
        do {
            Visit(n);
            if (!n->m_tried && !n->m_skip && !func_00125DC8(n->m_obj)) {
                if (func_00189750(mgr, ev->m_type, n->m_obj->m18, ev->m4, ev->m_params, 0)) {
                    found = 1;
                    break;
                }
                n->m_tried = 1;
            }
            if (m_restart[idx]) break;
            n = n->m_next;
        } while (n);
        }
        if (!found && m_restart[idx]) goto restart;
        if (found) func_00187D28(ev, 1, 0);
    }
}
