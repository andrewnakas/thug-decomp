/* sym: _vt$12ItA_00202220 = 0x00366AC0 */
/* sym: _vt$12ItB_00202220 = 0x00366AA8 */
/* sym: _vt$12ItC_00202220 = 0x00366AF8 */
/* sym: _$_10X_00202220 = 0x001FA8C0 */
/* sym: _$_10Y_00202220 = 0x001FA9B0 */
struct Ref_00202220 {
    int m0;
    int m_count;
    int Release() { return --m_count; }
};

class X_00202220 {
public:
    char pad0[8];
    Ref_00202220 m_ref;
    ~X_00202220();
};

class Y_00202220 {
public:
    char pad0[0xC];
    Ref_00202220 m_ref;
    ~Y_00202220();
};

struct HC_00202220 {
    char pad0[0x18];
    X_00202220* m18;
};

class HBase_00202220 {
public:
    char pad0[0x14];
    virtual ~HBase_00202220();
};

class HA_00202220 : public HBase_00202220 {
public:
    int m18;
    X_00202220* m1C;
};

class HB_00202220 : public HBase_00202220 {
public:
    char pad18[0x2C - 0x18];
    Y_00202220* m2C;
};

template <class T> struct Node_00202220 {
    int m0;
    T* m4;
    int m8;
    Node_00202220* mC;
    Node_00202220* Valid() { if (~(int)m4 == 0) return 0; return this; }
    T* GetData() { return m4; }
};

struct Owner_00202220 {
    Node_00202220<HC_00202220> mC;
    char pad10[0x8];
    Node_00202220<HA_00202220> mA;
    char pad28[0x8];
    Node_00202220<HB_00202220> mB;
};

#define IT_00202220(NAME, H)                                   \
class NAME {                                                    \
public:                                                         \
    int m0;                                                     \
    Node_00202220<H>* cur;                                      \
    NAME() { cur = 0; }                                         \
    virtual ~NAME() {}                                          \
    virtual void Run();                                         \
    H* Next()                                                   \
    {                                                           \
        cur = cur->mC->Valid();                                 \
        if (!cur) return 0;                                     \
        return cur->GetData();                                  \
    }                                                           \
    H* Advance(Node_00202220<H>* c)                             \
    {                                                           \
        cur = c->mC->Valid();                                   \
        if (!cur) return 0;                                     \
        return cur->GetData();                                  \
    }                                                           \
    H* First(Node_00202220<H>* h)                               \
    {                                                           \
        cur = h;                                                \
        return Next();                                          \
    }                                                           \
};

IT_00202220(ItA_00202220, HA_00202220)
IT_00202220(ItB_00202220, HB_00202220)
IT_00202220(ItC_00202220, HC_00202220)

void func_00202220(Owner_00202220* o)
{
    ItC_00202220 c;
    ItA_00202220 a;
    ItB_00202220 b;
    HA_00202220* ha = a.First(&o->mA);
    while (ha) {
        HA_00202220* next = a.Advance(a.cur);
        X_00202220* x = ha->m1C;
        if (x->m_ref.Release() == 0) delete x;
        delete ha;
        ha = next;
    }
    HB_00202220* hb = b.First(&o->mB);
    while (hb) {
        HB_00202220* next = b.Advance(b.cur);
        Y_00202220* y = hb->m2C;
        if (y->m_ref.Release() == 0) delete y;
        delete hb;
        hb = next;
    }
}
