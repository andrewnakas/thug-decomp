/* sym: _vt$14IterA_00201DD0 = 0x00366AF8 */
/* sym: _vt$14IterB_00201DD0 = 0x00366AC0 */
/* sym: _vt$14IterC_00201DD0 = 0x00366AA8 */
/* sym: _vt$14IterD_00201DD0 = 0x00366A90 */

struct Node_00201DD0 {
    int m0;
    void* m4;
    int m8;
    Node_00201DD0* mC;
    Node_00201DD0* m10;
    Node_00201DD0* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

struct List_00201DD0 {
    Node_00201DD0 head;
    int m14;
};

#define ITER_00201DD0(Name)                       \
    class Name {                                  \
    public:                                       \
        int m0;                                   \
        Node_00201DD0* cur;                       \
        Name() { cur = 0; }                       \
        virtual ~Name() {}                        \
        virtual void Run();                       \
        void* Next()                              \
        {                                         \
            cur = cur->mC->Valid();               \
            if (!cur) return 0;                   \
            return cur->GetData();                \
        }                                         \
        void* Advance(Node_00201DD0* c)           \
        {                                         \
            cur = c->mC->Valid();                 \
            if (!cur) return 0;                   \
            return cur->GetData();                \
        }                                         \
        void* First(List_00201DD0* l)             \
        {                                         \
            cur = &l->head;                       \
            return Next();                        \
        }                                         \
    };

ITER_00201DD0(IterA_00201DD0)
ITER_00201DD0(IterB_00201DD0)
ITER_00201DD0(IterC_00201DD0)
ITER_00201DD0(IterD_00201DD0)

class Item_00201DD0 : public Node_00201DD0 {
public:
    virtual ~Item_00201DD0();
};

struct Rec_00201DD0;

class Obj_00201DD0 : public Item_00201DD0 {
public:
    virtual ~Obj_00201DD0();
    Rec_00201DD0* m_rec;
};

extern "C" void func_001FA7A0(Rec_00201DD0* r, int flags);

struct Mgr_00201DD0 {
    List_00201DD0 m_a;
    List_00201DD0 m_b;
    List_00201DD0 m_c;
    char pad48[0x884 - 0x48];
    List_00201DD0 m_lists[256];
    List_00201DD0 m_d;
    List_00201DD0 m_e;
    void Clear();
};

void Mgr_00201DD0::Clear()
{
    IterA_00201DD0 a;
    IterB_00201DD0 b;
    IterC_00201DD0 c;
    IterD_00201DD0 d;
    Item_00201DD0* o;
    Item_00201DD0* n;
    o = (Item_00201DD0*)a.First(&m_a);
    if (o) {
        IterA_00201DD0* pa = &a;
        do {
            n = (Item_00201DD0*)pa->Advance(a.cur);
            delete o;
            o = n;
        } while (o);
    }
    for (o = (Item_00201DD0*)b.First(&m_b); o; o = n) {
        n = (Item_00201DD0*)b.Next();
        delete o;
    }
    for (o = (Item_00201DD0*)c.First(&m_c); o; o = n) {
        n = (Item_00201DD0*)c.Next();
        delete o;
    }
    for (int i = 0; i < 256; i++) {
        for (o = (Item_00201DD0*)c.First(&m_lists[i]); o; o = n) {
            n = (Item_00201DD0*)c.Next();
            delete o;
        }
    }
    Obj_00201DD0* p;
    Obj_00201DD0* q;
    for (p = (Obj_00201DD0*)d.First(&m_d); p; p = q) {
        q = (Obj_00201DD0*)d.Next();
        if (p->m_rec) func_001FA7A0(p->m_rec, 3);
        delete p;
    }
    for (p = (Obj_00201DD0*)d.First(&m_e); p; p = q) {
        q = (Obj_00201DD0*)d.Next();
        if (p->m_rec) func_001FA7A0(p->m_rec, 3);
        delete p;
    }
}
