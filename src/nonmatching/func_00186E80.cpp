/* fuzzy: 71.5 */
struct Obj_00186E80;

struct Link_00186E80 {
    int m0;
    Obj_00186E80* m_data;
    int m8;
    Link_00186E80* m_next;
};

struct Obj_00186E80 {
    int m0;
    Link_00186E80 m_children;
    int m14[2];
    unsigned int m_used;
    unsigned int m_marks;
};

extern "C" void func_00185058(Obj_00186E80* o);

class Node1873E0 {
public:
    int m0;
    Link_00186E80* m_cur;
    Node1873E0() : m_cur(0) {}
    virtual ~Node1873E0() {}
    virtual void Run();
    Obj_00186E80* Next()
    {
        Link_00186E80* n = m_cur->m_next;
        m_cur = (n->m_data == (Obj_00186E80*)-1) ? 0 : n;
        Obj_00186E80* r;
        if (m_cur) {
            r = m_cur->m_data;
        } else {
            r = 0;
        }
        return r;
    }
};

static inline unsigned int AllocBit(unsigned int& mask)
{
    unsigned int bit = 1;
    while (mask & bit) {
        bit <<= 1;
    }
    mask |= bit;
    return bit;
}

extern "C" void func_00186E80(Obj_00186E80* self)
{
    Node1873E0 it;
    unsigned int bit = AllocBit(self->m_used);
    it.m_cur = &self->m_children;
    for (Obj_00186E80* o = it.Next(); o; o = it.Next()) {
        o->m_marks &= ~bit;
    }
    do {
        self->m_marks &= ~bit;
        it.m_cur = &self->m_children;
        Obj_00186E80* o = it.Next();
        while (o) {
            Obj_00186E80* cur = o;
            o = it.Next();
            if (!(cur->m_marks & bit)) {
                cur->m_marks |= bit;
                func_00185058(cur);
                if (self->m_marks & bit) {
                    break;
                }
            }
        }
    } while (self->m_marks & bit);
    self->m_used &= ~bit;
}
