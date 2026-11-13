/* sym: _vt$12ItA_001FF410 = 0x00366AC0 */
/* sym: _vt$12ItB_001FF410 = 0x00366AA8 */
/* sym: _vt$12ItC_001FF410 = 0x00366AF8 */
class HBase_001FF410 {
public:
    char pad0[0x14];
    virtual ~HBase_001FF410();
};

class HC_001FF410 {
public:
    char pad0[0x1C];
    unsigned int m1C;
};

class HA_001FF410 : public HBase_001FF410 {
public:
    unsigned int m18;
    char pad1C[0x28 - 0x1C];
    unsigned int m28;
};

class HB_001FF410 : public HBase_001FF410 {
public:
    char pad18[0x20 - 0x18];
    unsigned int m20;
    char pad24[0x28 - 0x24];
    unsigned int m28;
};

template <class T> struct Node_001FF410 {
    int m0;
    T* m4;
    int m8;
    Node_001FF410* mC;
    Node_001FF410* Valid() { if (~(int)m4 == 0) return 0; return this; }
    T* GetData() { return m4; }
};

struct Owner_001FF410 {
    Node_001FF410<HC_001FF410> mC;
    char pad10[0x8];
    Node_001FF410<HA_001FF410> mA;
    char pad28[0x8];
    Node_001FF410<HB_001FF410> mB;
};

#define IT_001FF410(NAME, H)                                   \
class NAME {                                                    \
public:                                                         \
    int m0;                                                     \
    Node_001FF410<H>* cur;                                      \
    NAME() { cur = 0; }                                         \
    virtual ~NAME() {}                                          \
    virtual void Run();                                         \
    H* Next()                                                   \
    {                                                           \
        cur = cur->mC->Valid();                                 \
        if (!cur) return 0;                                     \
        return cur->GetData();                                  \
    }                                                           \
    H* Advance(Node_001FF410<H>* c)                             \
    {                                                           \
        cur = c->mC->Valid();                                   \
        if (!cur) return 0;                                     \
        return cur->GetData();                                  \
    }                                                           \
    H* First(Node_001FF410<H>* h)                               \
    {                                                           \
        cur = h;                                                \
        return Next();                                          \
    }                                                           \
};

IT_001FF410(ItA_001FF410, HA_001FF410)
IT_001FF410(ItB_001FF410, HB_001FF410)
IT_001FF410(ItC_001FF410, HC_001FF410)

extern "C" unsigned int func_00202788(Owner_001FF410* o);

struct Obj_001FF410 {
    unsigned int m0;
    bool Check(Owner_001FF410* o);
};

bool Obj_001FF410::Check(Owner_001FF410* o)
{
    {
        ItC_001FF410 c;
        HC_001FF410* hc = c.First(&o->mC);
        while (hc) {
            if (m0 >= hc->m1C) return true;
            hc = c.Next();
        }
    }
    {
        ItA_001FF410 a;
        HA_001FF410* ha = a.First(&o->mA);
        while (ha) {
            if (!ha->m18 || m0 < ha->m28 || m0 - ha->m18 > func_00202788(o)) return true;
            ha = a.Next();
        }
    }
    {
        ItB_001FF410 b;
        HB_001FF410* hb = b.First(&o->mB);
        while (hb) {
            if (!hb->m20 || m0 < hb->m28 || m0 - hb->m20 > func_00202788(o)) return true;
            hb = b.Next();
        }
    }
    return false;
}
