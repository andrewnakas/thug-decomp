/* sym: _vt$12ItA_00202BC8 = 0x00366AC0 */
/* sym: _vt$12ItB_00202BC8 = 0x00366AA8 */
struct HA_00202BC8 {
    char pad0[0x18];
    int m18;
    int m1C;
    int m20;
};

struct HB_00202BC8 {
    char pad0[0x1C];
    int m1C;
    int m20;
};

template <class T> struct Node_00202BC8 {
    int m0;
    T* m4;
    int m8;
    Node_00202BC8* mC;
    Node_00202BC8* Valid() { if (~(int)m4 == 0) return 0; return this; }
    T* GetData() { return m4; }
};

struct Owner_00202BC8 {
    char pad0[0x18];
    Node_00202BC8<HA_00202BC8> mA;
    char pad28[0x8];
    Node_00202BC8<HB_00202BC8> mB;
};

class ItA_00202BC8 {
public:
    int m0;
    Node_00202BC8<HA_00202BC8>* cur;
    ItA_00202BC8() { cur = 0; }
    virtual ~ItA_00202BC8() {}
    virtual void Run();
    HA_00202BC8* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    HA_00202BC8* First(Node_00202BC8<HA_00202BC8>* h)
    {
        cur = h;
        return Next();
    }
};

class ItB_00202BC8 {
public:
    int m0;
    Node_00202BC8<HB_00202BC8>* cur;
    ItB_00202BC8() { cur = 0; }
    virtual ~ItB_00202BC8() {}
    virtual void Run();
    HB_00202BC8* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    HB_00202BC8* First(Node_00202BC8<HB_00202BC8>* h)
    {
        cur = h;
        return Next();
    }
};

void func_00202BC8(Owner_00202BC8* o, int id)
{
    ItA_00202BC8 a;
    ItB_00202BC8 b;
    for (HA_00202BC8* h = a.First(&o->mA); h; h = a.Next()) {
        if (h->m20 == id) h->m18 = 0;
    }
    for (HB_00202BC8* h = b.First(&o->mB); h; h = b.Next()) {
        if (h->m1C == id) h->m20 = 0;
    }
}
