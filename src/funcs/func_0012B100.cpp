struct Obj_0012B100;
struct Handle_0012B100;

extern "C" void func_00183C98(Obj_0012B100* o, Handle_0012B100* h);
extern "C" void func_00183CB8(Obj_0012B100* o, Handle_0012B100* h);

struct Obj_0012B100 {
    char pad[0x18];
    int m18;
    char pad1C[0x44];
    Obj_0012B100* m60;
};

struct Handle_0012B100 {
    Obj_0012B100* m_obj;
    Handle_0012B100* m_prev;
    Handle_0012B100* m_next;
    Handle_0012B100(Obj_0012B100* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_0012B100(const Handle_0012B100& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012B100()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012B100& operator=(Obj_0012B100* o)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = o;
        if (o)
            func_00183C98(o, this);
        return *this;
    }
    Obj_0012B100* operator->() const { return m_obj; }
    operator Obj_0012B100*() const { return m_obj; }
};

static inline Handle_0012B100 Make_0012B100(const Handle_0012B100& t)
{
    return t;
}

class Struct1E6978 {
public:
    int m_w[2];
    Struct1E6978();
    ~Struct1E6978();
};

struct Event_0012B100 {
    unsigned int m0;
    char pad4[0xC];
    void* m10;
};

struct C_0012B100;

extern "C" int func_00184828(void* o, Event_0012B100* e, int a);
extern "C" void func_00187D28(Event_0012B100* e, int a, int b);
extern "C" int func_00187D68(Event_0012B100* e);
extern "C" void func_00189750(void* mgr, unsigned int type, int target, unsigned int id, void* s, int a);
extern "C" void func_001E7200(Struct1E6978* s, unsigned int id, int v);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" bool func_00184078(Obj_0012B100* o, unsigned int id, int* out);
extern "C" Obj_0012B100* func_001241E8(C_0012B100* o, int a, int* idx);
extern "C" Obj_0012B100* func_00124238(C_0012B100* o, int i);
extern "C" void func_0012BA50(C_0012B100* self);
extern "C" void func_0012B728(C_0012B100* o, int a, int b, int c);
extern "C" void func_0012BAA8(C_0012B100* o);
extern "C" void func_0012B910(C_0012B100* o, int a);
extern void* D_0038C7B0;

struct C_0012B100 {
    char pad[0x18];
    int m18;
    char pad1C[0x38];
    Obj_0012B100* m54;
    char pad58[0x148];
    int m1A0;
    int m1A4;
    int m1A8;
    int m1AC;
    char pad1B0[0x8];
    int m1B8;
    char pad1BC[0xC];
    int m1C8;
    char pad1CC[0x4];
    int m1D0;
    bool Handle(Event_0012B100* e);
};

bool C_0012B100::Handle(Event_0012B100* e)
{
    if (!func_00184828(this, e, 0))
        return false;
    void* mgr = D_0038C7B0;
    if (e->m0 == 0x3056434F) {
        int done = 0;
        if (m1A4) {
            int idx;
            Handle_0012B100 sel = Make_0012B100(func_001241E8(this, m1A4, &idx));
            if (!sel) {
                Handle_0012B100 h = Make_0012B100(func_00124238(this, m1A0));
                if (h) {
                    m1A4 = h->m18;
                    func_0012BA50(this);
                    done = 1;
                } else {
                    m1A0 = -1;
                    func_0012B728(this, 1, 1, 1);
                    done = 1;
                }
            } else {
                m1A0 = idx;
                func_0012BA50(this);
            }
        } else {
            func_0012B728(this, 1, 1, 1);
            done = 1;
        }
        if (done && m1A8) {
            func_0012B728(this, 1, 1, 1);
            if (m1A4) {
                Struct1E6978 s;
                func_001E7200(&s, 0xB30D9965, m1AC);
                func_00189750(mgr, 0x9D3FB516, m1A4, 0x36B2EE74, &s, 0);
            }
        }
        func_0012BAA8(this);
        func_00187D28(e, m18, 0);
    }
    if (e->m0 == 0x9D3FB516 && !m1A8) {
        m1AC = func_00187D68(e);
        int v = -1;
        if (e->m10 && func_001E7DE8(e->m10, 0xFACF9A8B, &v, 0)) {
            int best = -1;
            m1D0 = v;
            Handle_0012B100 h = m54;
            int i = 0;
            while (h) {
                int p = -1;
                if (func_00184078(h, 0x5B92F8DD, &p)) {
                    if (p <= v)
                        best = i;
                }
                h = h->m60;
                i++;
            }
            if (best != -1) {
                m1A0 = best;
                m1A4 = 1;
            }
        }
        int id;
        if (e->m10 && func_001E8398(e->m10, 0x229D3DE4, &id, 0)) {
            Handle_0012B100 h = m54;
            int i = 0;
            while (h) {
                if (id == h->m18) {
                    m1A4 = id;
                    m1A0 = i;
                    break;
                }
                i++;
                h = h->m60;
            }
        }
        m1A8 = 1;
        if (m1A4) {
            func_0012B728(this, 1, 1, 0);
            if (m1A4)
                func_00189750(mgr, 0x9D3FB516, m1A4, 0x36B2EE74, e->m10, 0);
        }
        func_00187D28(e, m18, 0);
    }
    if (e->m0 == 0x4ADF0CD3 && m1A8) {
        m1A8 = 0;
        if (m1A4)
            func_00189750(mgr, 0x4ADF0CD3, m1A4, 0x36B2EE74, 0, 0);
        func_00187D28(e, m18, 0);
    }
    if (((e->m0 == 0x30A4F836 && m1B8) || (e->m0 == 0x6949DB75 && !m1B8)) && m1A8) {
        if (m1C8) {
            func_0012B910(this, -1);
            func_00187D28(e, m18, 0);
        }
    }
    if (((e->m0 == 0x0FD1AC26 && m1B8) || (e->m0 == 0x05DDD87C && !m1B8)) && m1A8) {
        if (m1C8) {
            func_0012B910(this, 1);
            func_00187D28(e, m18, 0);
        }
    }
    return true;
}
