/* fuzzy: 89.7 */
/* blocked: First()'s if/else is folded into 'a0 = 0; if (cur) a0 = cur->m_data' by jump2 because the inline's result pseudo (145) takes $a0 from conn's copy preferences ($a0/$a1); the game keeps it in $v0 (same reg as the tested cur, which blocks the fold). oracle fr 145->$v0 takes 74 -> 13 words; the rest is the vtable/0xFF pseudo order (sched1 live ranges) and Next's s0=0 hoist. Tried: polarity of Advance, sibling-style Valid/First (func_002B4250, func_00200EC0), First via m_cur: no change. */
struct Link_00200998 {
    int m0;
    void* m_data;
    int m8;
    Link_00200998* m_prev;
    Link_00200998* m_next;
    void* Data() { return m_data; }
    Link_00200998* Valid() { return ~(unsigned int)m_data != 0 ? this : 0; }
    bool IsEnd() { return ~(int)m_data == 0; }
    Link_00200998* Nx()
    {
        if (m_prev->IsEnd())
            return 0;
        return m_prev;
    }
};

// Iterator with vtable D_00366B58: the class of func_002016D8 (its vtable name is
// already mapped in cxx_symbols_lane2.txt). Here the destructor is inlined.
class Node104D78_002016D8 {
public:
    int m0;
    Link_00200998* m_cur;
    Node104D78_002016D8() : m_cur(0) {}
    virtual ~Node104D78_002016D8() {}
    virtual void Run();
    void* Next()
    {
        m_cur = m_cur->Nx();
        if (!m_cur)
            return 0;
        return m_cur->m_data;
    }
    void* Advance(Link_00200998* c)
    {
        m_cur = c->m_prev->Valid();
        if (!m_cur)
            return 0;
        return m_cur->Data();
    }
    void* First(Link_00200998* head)
    {
        m_cur = head;
        return Advance(m_cur);
    }
};

struct Mgr_00200998;

extern "C" void* func_001FEA20(Mgr_00200998* self);
extern "C" bool func_00202738(void* conn);
extern "C" void func_002006C8(Mgr_00200998* self, void* conn, unsigned char msg, unsigned short size, void* data,
                              int a, unsigned char b, int c, int d);

struct Mgr_00200998 {
    char pad[0x42D8];
    Link_00200998 m_conns;
    void Send(int target, unsigned char msg, unsigned short size, void* data, int a, unsigned char b, int c,
              int d);
};

void Mgr_00200998::Send(int target, unsigned char msg, unsigned short size, void* data, int a, unsigned char b,
                        int c, int d)
{
    Node104D78_002016D8 iter;
    Node104D78_002016D8* it = &iter;
    if (target == 0xFF) {
        for (void* conn = it->First(&m_conns); conn; conn = iter.Next()) {
            if (func_00202738(conn)) {
                func_002006C8(this, conn, msg, size, data, a, b, c, d);
            }
        }
    } else {
        void* conn = func_001FEA20(this);
        if (func_00202738(conn)) {
            func_002006C8(this, conn, msg, size, data, a, b, c, d);
        }
    }
}
