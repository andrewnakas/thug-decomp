extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);

struct Ref_0012DC18 {
    void* m_p;
    Ref_0012DC18* m_prev;
    Ref_0012DC18* m_next;
    void Set(void* o)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = o;
        if (o) {
            func_00183C98(o, this);
        }
    }
    Ref_0012DC18()
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
    }
    Ref_0012DC18(const Ref_0012DC18& o)
    {
        m_prev = 0;
        m_next = 0;
        m_p = 0;
        Set(o.m_p);
    }
    ~Ref_0012DC18()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

class Mgr_0012DC18;
extern "C" void* func_0012E438(Mgr_0012DC18* self, int a, int b);
extern "C" Ref_0012DC18 func_0012DB48(Mgr_0012DC18* self, void* e, int c);

class Mgr_0012DC18 {
public:
    int m0;
    Ref_0012DC18 Get(int a, int b, int c);
};

Ref_0012DC18 Mgr_0012DC18::Get(int a, int b, int c)
{
    void* e = func_0012E438(this, a, b);
    if (e) {
        Ref_0012DC18 r = func_0012DB48(this, e, c);
        return r;
    }
    Ref_0012DC18 r;
    return r;
}
