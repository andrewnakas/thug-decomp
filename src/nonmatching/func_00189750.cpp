/* fuzzy: 74.0 */
/* sym: __11Ev_00189750 = 0x00187C78 */
/* sym: _$_11Ev_00189750 = 0x00187C88 */
extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, unsigned int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

inline void* operator new[](unsigned int size)
{
    return func_0010A638(D_00388A70, size, 1, 0);
}

inline void operator delete[](void* p)
{
    func_0010A8D8(D_00388A70, p);
}

struct Ev_00189750 {
    unsigned int m_key;
    int m4;
    unsigned int m_id;
    int m_flags;
    void* m10;
    Ev_00189750();
    ~Ev_00189750();
    int Handled() const { return (m_flags >> 1) & 1; }
};

struct Target_00189750 {
    char pad0[0xC8];
    int mC8;
};

struct Handle_00189750 {
    void* m_obj;
    Handle_00189750* m_prev;
    Handle_00189750* m_next;
    Handle_00189750()
    {
        m_prev = 0;
        m_next = 0;
        m_obj = 0;
    }
    ~Handle_00189750()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_00189750& operator=(void* o)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = o;
        if (o) {
            func_00183C98(o, this);
        }
        return *this;
    }
};

struct Data_00189750 {
    char pad0[0xE8];
    int mE8;
};

struct N_00189750 {
    int m0;
    Data_00189750* m_data;
    int m_pri;
    N_00189750* m_next;
    N_00189750* m_prev;
    N_00189750* GetNext()
    {
        N_00189750* n = m_next;
        if ((int)n->m_data == -1) {
            n = 0;
        }
        return n;
    }
    N_00189750* NextA() { return (int)m_next->m_data != -1 ? m_next : 0; }
};

struct Group_00189750 {
    int m0;
    N_00189750 m_list;
};

struct Slot_00189750 {
    unsigned int m_obj;
    unsigned int m_key;
    unsigned int m_id;
};

struct Handler_00189750 {
    int m0[2];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Handle(Ev_00189750* ev, int a);
};

struct Mgr_00189750 {
    char pad0[0x10];
    void* m10;
    char pad14[0x1C - 0x14];
    int m_lock;
    char m20[0xB034 - 0x20];
    int mB034;
    Slot_00189750 m_slots[40];
    int Send(unsigned int key, unsigned int id, int a, void* params, int broadcast);
};

extern "C" void func_00187D28(Ev_00189750* ev, int a, int b);
extern "C" void func_00188DF0(void* q, unsigned int key, unsigned int id, int a, int b, int c, int d);
extern "C" void func_00189018(void* q, int a, int b);
extern "C" void func_00189340(Mgr_00189750* m, Ev_00189750* ev, int a);
extern "C" Handler_00189750* func_001895B0(Mgr_00189750* m);
extern "C" void func_00189BC0(Mgr_00189750* m, Ev_00189750* ev, int a, int b);
extern "C" Group_00189750* func_0018AE38(void* table, unsigned int* key, int a);
extern "C" void func_001EE608(Target_00189750* t);
extern "C" Target_00189750* func_001F0708(unsigned int id);
extern "C" Data_00189750* func_001F0D00(unsigned int id);
extern "C" void func_001F1200(Data_00189750* d, Ev_00189750* ev, int broadcast);

int Mgr_00189750::Send(unsigned int key, unsigned int id, int a, void* params, int broadcast)
{
    m_lock++;
    func_00188DF0(m20, key, id, a, mB034, 0, 0);
    mB034 = 0;
    Ev_00189750 ev;
    ev.m_key = key;
    ev.m4 = a;
    ev.m_id = id;
    ev.m10 = params;
    if (broadcast) {
        Group_00189750* g = func_0018AE38(m10, &key, 1);
        if (g) {
            N_00189750* head = &g->m_list;
            int count = 0;
            N_00189750* n = head->NextA();
            if (n) {
                do {
                    n = n->GetNext();
                    count++;
                } while (n);
            }
            if (count == 1) {
                func_001F1200(head->GetNext()->m_data, &ev, broadcast);
            } else {
                Data_00189750** objs = new Data_00189750*[count];
                Handle_00189750* refs = new Handle_00189750[count];
                Handle_00189750* r = refs;
                Data_00189750** o = objs;
                N_00189750* m = head->NextA();
                if (m) {
                    do {
                        *o = m->m_data;
                        *r = &m->m_data->mE8;
                        m = m->NextA();
                        r++;
                        o++;
                    } while (m);
                }
                for (int i = 0; i < count; i++) {
                    if (refs[i].m_obj) {
                        func_001F1200(objs[i], &ev, broadcast);
                    }
                }
                delete[] refs;
                delete[] objs;
            }
        }
    } else {
        func_00189340(this, &ev, 0);
        if (ev.m_id != 0x36B2EE74 && !ev.Handled()) {
            Handler_00189750* h = func_001895B0(this);
            if (h) {
                h->Handle(&ev, 0);
            } else {
                Data_00189750* d = func_001F0D00(ev.m_id);
                if (!d) {
                    func_00189018(m20, 1, 0x400);
                }
                func_001F1200(d, &ev, 0);
            }
        }
    }
    Slot_00189750* s = m_slots;
    for (int i = 0; i < 40; i++, s++) {
        if (s->m_key == key) {
            if (s->m_id == id || s->m_id == 0 || id == 0x36B2EE74 || broadcast) {
                s->m_key = 0;
                Target_00189750* t = func_001F0708(s->m_obj);
                if (t) {
                    func_001EE608(t);
                    func_00187D28(&ev, 2, t->mC8);
                    break;
                }
            }
        }
    }
    if (!ev.Handled()) {
        func_00189BC0(this, &ev, 3, 0);
    }
    m_lock--;
    return ev.Handled();
}
