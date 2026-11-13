/* fuzzy: 82.4 */
struct Link_00200998 {
    int m0;
    void* m_data;
    int m8;
    Link_00200998* m_prev;
    Link_00200998* m_next;
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
        Link_00200998* n = m_cur->m_prev;
        m_cur = (n->m_data != (void*)-1) ? n : 0;
        if (m_cur) {
            return m_cur->m_data;
        }
        return 0;
    }
    void* First(Link_00200998* head)
    {
        m_cur = head;
        return Next();
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
