/* fuzzy: 71.3 */
struct LNode_00104A80;

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

struct LNode_00104A80 {
    int m0;
    Obj_00104A80* data;
    void* vptr;
    LNode_00104A80* next;
    LNode_00104A80* Valid()
    {
        if (data == (Obj_00104A80*)-1) {
            return 0;
        }
        return this;
    }
    LNode_00104A80* Next() { return next->Valid(); }
};

class Node104D78 {
public:
    int m0;
    LNode_00104A80* m4;
    Node104D78(LNode_00104A80* head) { m4 = head; }
    virtual ~Node104D78() {}
    virtual void Run();
    Obj_00104A80* Next()
    {
        m4 = m4->Next();
        return m4 ? m4->data : 0;
    }
};

struct Mgr_00104A80 {
    int m0;
    int m4;
    LNode_00104A80 head;
    int m18;
    int m1C;
    int m20;
    int m24;
};

extern "C" void func_00104A80(Mgr_00104A80* m, int unused, int mask)
{
    if (m->m4 != 0) {
        return;
    }
    m->m20++;
    do {
        Node104D78 it(&m->head);
        Node104D78* p = &it;
        Obj_00104A80* o = p->Next();
        m->m24 = 0;
        while (o) {
            Obj_00104A80* cur = o;
            o = p->Next();
            if (cur->m4 == 0 && cur->m10 != m->m20) {
                cur->m10 = m->m20;
                if ((cur->m14 & mask) == 0) {
                    cur->Update();
                }
            }
            if (m->m24) {
                break;
            }
        }
    } while (m->m24);
}
