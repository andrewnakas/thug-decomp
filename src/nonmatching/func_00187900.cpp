/* fuzzy: 95.2 */
/* blocked: same residue as func_00186E80 (movn vs movz in the second loop, a1/a2 swap); sibling iterator idioms no better; directed search best 7 words. */
/* sym: _vt$11It_00187900 = 0x00361AA0 */

struct N_00187900 {
    int m0;
    void* m_data;
    int m_pri;
    N_00187900* m_next;
    N_00187900* m_prev;
    N_00187900* Valid() { return ~(int)m_data ? this : 0; }
    void* GetData() { return m_data; }
};

struct It_00187900 {
    int m_0;
    N_00187900* m_cur;
    It_00187900() { m_cur = 0; }
    virtual void Reset();
    virtual ~It_00187900() {}
    void* Next()
    {
        m_cur = m_cur->m_next->Valid();
        if (!m_cur) {
            return 0;
        }
        return m_cur->GetData();
    }
    void* First(N_00187900* h)
    {
        m_cur = h;
        return Next();
    }
    void* Advance(N_00187900* c)
    {
        m_cur = c->m_next->Valid();
        if (!m_cur) {
            return 0;
        }
        return m_cur->GetData();
    }
};

struct Obj_00187900 {
    char pad[0x20];
    unsigned int m20;
};

struct Bits_00187900 {
    unsigned int m_bits;
    unsigned int Alloc()
    {
        unsigned int bit = 1;
        while (m_bits & bit) {
            bit <<= 1;
        }
        m_bits |= bit;
        return bit;
    }
};

struct Mgr_00187900 {
    int m0;
    N_00187900 m_list;
    char pad18[0x1C - 0x18];
    Bits_00187900 m_bits;
    unsigned int m_dirty;
    void ForEach(void (*fn)(Obj_00187900* o, void* arg), void* arg);
};

void Mgr_00187900::ForEach(void (*fn)(Obj_00187900* o, void* arg), void* arg)
{
    It_00187900 it;
    unsigned int bit = m_bits.Alloc();
    Obj_00187900* q = (Obj_00187900*)it.First(&m_list);
    if (q) {
        It_00187900* p = &it;
        do {
            q->m20 &= ~bit;
            q = (Obj_00187900*)p->Advance(it.m_cur);
        } while (q);
    }
restart:
    {
        m_dirty &= ~bit;
        Obj_00187900* o = (Obj_00187900*)it.First(&m_list);
        if (o) {
            It_00187900* p = &it;
            do {
                Obj_00187900* c = o;
                o = (Obj_00187900*)p->Advance(it.m_cur);
                if (!(c->m20 & bit)) {
                    c->m20 |= bit;
                    fn(c, arg);
                    if (m_dirty & bit) {
                        goto restart;
                    }
                }
            } while (o);
        }
    }
    if (m_dirty & bit) {
        goto restart;
    }
    m_bits.m_bits &= ~bit;
}
