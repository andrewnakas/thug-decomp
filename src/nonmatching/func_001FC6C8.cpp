/* fuzzy: 91.1 */
/* sym: _vt$12ItA_001FC6C8 = 0x00366AC0 */
/* sym: _vt$12ItB_001FC6C8 = 0x00366AA8 */
/* sym: _$_10X_001FC6C8 = 0x001FA8C0 */
/* sym: _$_10Y_001FC6C8 = 0x001FA9B0 */
struct Ref_001FC6C8 {
    int m0;
    int m_count;
    int Release() { return --m_count; }
};

class X_001FC6C8 {
public:
    char pad0[8];
    Ref_001FC6C8 m_ref;
    ~X_001FC6C8();
};

class Y_001FC6C8 {
public:
    char pad0[0xC];
    Ref_001FC6C8 m_ref;
    ~Y_001FC6C8();
};

struct HC_001FC6C8 {
    char pad0[0x18];
    X_001FC6C8* m18;
};

class HBase_001FC6C8 {
public:
    char pad0[0x14];
    virtual ~HBase_001FC6C8();
};

class HA_001FC6C8 : public HBase_001FC6C8 {
public:
    int m18;
    X_001FC6C8* m1C;
    unsigned short m20;
};

class HB_001FC6C8 : public HBase_001FC6C8 {
public:
    char pad18[0x1C - 0x18];
    unsigned short m1C;
    int m20;
    char pad24[0x2C - 0x24];
    Y_001FC6C8* m2C;
};

template <class T> struct Node_001FC6C8 {
    int m0;
    T* m4;
    int m8;
    Node_001FC6C8* mC;
    Node_001FC6C8* Valid() { if (~(int)m4 == 0) return 0; return this; }
    T* GetData() { return m4; }
};

struct Owner_001FC6C8 {
    Node_001FC6C8<HC_001FC6C8> mC;
    char pad10[0x8];
    Node_001FC6C8<HA_001FC6C8> mA;
    char pad28[0x8];
    Node_001FC6C8<HB_001FC6C8> mB;
    char pad40[0x68 - 0x40];
    unsigned int m68;
    char pad6C[0x20B4 - 0x6C];
    unsigned int m20B4;
};

#define IT_001FC6C8(NAME, H)                                   \
class NAME {                                                    \
public:                                                         \
    int m0;                                                     \
    Node_001FC6C8<H>* cur;                                      \
    NAME() { cur = 0; }                                         \
    virtual ~NAME() {}                                          \
    virtual void Run();                                         \
    H* Next()                                                   \
    {                                                           \
        cur = cur->mC->Valid();                                 \
        if (!cur) return 0;                                     \
        return cur->GetData();                                  \
    }                                                           \
    H* Advance(Node_001FC6C8<H>* c)                             \
    {                                                           \
        cur = c->mC->Valid();                                   \
        if (!cur) return 0;                                     \
        return cur->GetData();                                  \
    }                                                           \
    H* First(Node_001FC6C8<H>* h)                               \
    {                                                           \
        cur = h;                                                \
        return Next();                                          \
    }                                                           \
};

IT_001FC6C8(ItA_001FC6C8, HA_001FC6C8)
IT_001FC6C8(ItB_001FC6C8, HB_001FC6C8)

extern unsigned int D_0038EC64;
extern "C" int func_00202778(Owner_001FC6C8* o);
extern "C" int func_00202768(Owner_001FC6C8* o);
extern "C" void func_001FE388(unsigned int* p, unsigned int v);

struct Guard_001FC6C8 {
    int m0;
    int m4;
    int m8;
    int mC;
    Guard_001FC6C8() { m0 = 1; }
};

struct Obj_001FC6C8 {
    unsigned short* m0;
    int m4;
    long m8;
    unsigned int* m10;
    Owner_001FC6C8* m14;
    unsigned int m18;
    int Run();
};

int Obj_001FC6C8::Run()
{
    m8 = 2;
    unsigned int last = 0;
    unsigned short* key = m0;
    ItA_001FC6C8 a;
    ItB_001FC6C8 b;
    if (m18 & 1) return 3;
    HA_001FC6C8* ha = a.First(&m14->mA);
    if (ha) {
        ItA_001FC6C8* p = &a;
        do {
            HA_001FC6C8* next = p->Advance(a.cur);
            if (*key == ha->m20 && ha->m18) {
                X_001FC6C8* x = ha->m1C;
                if (x->m_ref.Release() == 0) delete x;
                last = ha->m18;
                delete ha;
            }
            ha = next;
        } while (ha);
    }
    HB_001FC6C8* hb = b.First(&m14->mB);
    while (hb) {
        HB_001FC6C8* next = b.Advance(b.cur);
        if (*key == hb->m1C && hb->m20) {
            Y_001FC6C8* y = hb->m2C;
            if (y->m_ref.Release() == 0) delete y;
            last = hb->m20;
            delete hb;
        }
        hb = next;
    }
    if (func_00202778(m14)) {
        Guard_001FC6C8 g;
        Owner_001FC6C8* o = m14;
        if (o->m68 & 1) {
            if (last) {
                unsigned int d = *m10 - last;
                unsigned int lim;
                if (func_00202768(o)) lim = 0; else lim = o->m20B4;
                if (lim < d) {
                    unsigned int v = D_0038EC64;
                    if (!(v < d)) v = d;
                    func_001FE388(&m14->m20B4, v);
                }
            }
        }
    }
    return 1;
}
