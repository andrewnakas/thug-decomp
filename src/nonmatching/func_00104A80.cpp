/* fuzzy: 74.4 */
/* sym: _vt$11It_00104A80 = 0x0035A988 */
class Obj_00104A80 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    virtual void Update();
};

struct Node_00104A80 {
    int m0;
    Obj_00104A80* m_data;
    int m8;
    Node_00104A80* m_prev;
    Node_00104A80* m_next;
    Node_00104A80* Valid()
    {
        if (m_data == (Obj_00104A80*)-1) {
            return 0;
        }
        return this;
    }
    Obj_00104A80* GetData() { return m_data; }
};

class It_00104A80 {
public:
    int m0;
    Node_00104A80* m_cur;
    It_00104A80() { m_cur = 0; }
    virtual ~It_00104A80() {}
    virtual void Run();
    Obj_00104A80* Advance(Node_00104A80* c)
    {
        m_cur = c->m_prev->Valid();
        if (m_cur) {
            return m_cur->GetData();
        }
        return 0;
    }
    Obj_00104A80* First(Node_00104A80* h)
    {
        m_cur = h;
        return Advance(m_cur);
    }
};

struct Mgr_00104A80 {
    int m0;
    int m_locked;
    Node_00104A80 m_head;
    int m1C;
    int m_pass;
    int m_restart;
};

extern "C" void func_00104A80(Mgr_00104A80* m, int unused, int mask)
{
    if (m->m_locked != 0) {
        return;
    }
    m->m_pass++;
    do {
        It_00104A80 it;
        It_00104A80* p0 = &it;
        Obj_00104A80* o = p0->First(&m->m_head);
        m->m_restart = 0;
        if (o) {
            It_00104A80* p = &it;
            do {
                Obj_00104A80* nx = p->Advance(it.m_cur);
                if (o->m4 == 0 && o->m10 != m->m_pass) {
                    o->m10 = m->m_pass;
                    if ((o->m14 & mask) == 0) {
                        o->Update();
                    }
                }
                if (m->m_restart) {
                    break;
                }
                o = nx;
            } while (o);
        }
    } while (m->m_restart);
}
