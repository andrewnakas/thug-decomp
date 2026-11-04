/* sym: _vt$12ItA_00202418 = 0x00366AC0 */
/* sym: _vt$12ItB_00202418 = 0x00366AA8 */
/* sym: _vt$12ItC_00202418 = 0x00366AF8 */
/* sym: _$_10X_00202418 = 0x001FA8C0 */
/* sym: _$_10Y_00202418 = 0x001FA9B0 */
struct Ref_00202418 {
    int m0;
    int m_count;
    int Release() { return --m_count; }
};

class X_00202418 {
public:
    char pad0[8];
    Ref_00202418 m_ref;
    ~X_00202418();
};

class Y_00202418 {
public:
    char pad0[0xC];
    Ref_00202418 m_ref;
    ~Y_00202418();
};

struct HC_00202418 {
    char pad0[0x18];
    X_00202418* m18;
};

struct HA_00202418 {
    char pad0[0x1C];
    X_00202418* m1C;
};

struct HB_00202418 {
    char pad0[0x2C];
    Y_00202418* m2C;
};

template <class T> struct Node_00202418 {
    int m0;
    T* m4;
    int m8;
    Node_00202418* mC;
    Node_00202418* Valid() { if (~(int)m4 == 0) return 0; return this; }
    T* GetData() { return m4; }
};

struct Owner_00202418 {
    Node_00202418<HC_00202418> mC;
    char pad10[0x8];
    Node_00202418<HA_00202418> mA;
    char pad28[0x8];
    Node_00202418<HB_00202418> mB;
};

#define IT_00202418(NAME, H)                                   \
class NAME {                                                    \
public:                                                         \
    int m0;                                                     \
    Node_00202418<H>* cur;                                      \
    NAME() { cur = 0; }                                         \
    virtual ~NAME() {}                                          \
    virtual void Run();                                         \
    H* Next()                                                   \
    {                                                           \
        cur = cur->mC->Valid();                                 \
        if (!cur) return 0;                                     \
        return cur->GetData();                                  \
    }                                                           \
    H* Advance(Node_00202418<H>* c)                             \
    {                                                           \
        cur = c->mC->Valid();                                   \
        if (!cur) return 0;                                     \
        return cur->GetData();                                  \
    }                                                           \
    H* First(Node_00202418<H>* h)                               \
    {                                                           \
        cur = h;                                                \
        return Next();                                          \
    }                                                           \
};

IT_00202418(ItA_00202418, HA_00202418)
IT_00202418(ItB_00202418, HB_00202418)
IT_00202418(ItC_00202418, HC_00202418)

void func_00202418(Owner_00202418* o)
{
    ItC_00202418 c;
    ItA_00202418 a;
    ItB_00202418 b;
    HC_00202418* hc = c.First(&o->mC);
    if (hc) {
        ItC_00202418* p = &c;
        do {
            HC_00202418* next = p->Advance(c.cur);
            X_00202418* x = hc->m18;
            if (x->m_ref.Release() == 0) delete x;
            hc = next;
        } while (hc);
    }
    HA_00202418* ha = a.First(&o->mA);
    while (ha) {
        HA_00202418* next = a.Advance(a.cur);
        X_00202418* x = ha->m1C;
        if (x->m_ref.Release() == 0) delete x;
        ha = next;
    }
    HB_00202418* hb = b.First(&o->mB);
    while (hb) {
        HB_00202418* next = b.Advance(b.cur);
        Y_00202418* y = hb->m2C;
        if (y->m_ref.Release() == 0) delete y;
        hb = next;
    }
}
