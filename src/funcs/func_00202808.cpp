/* sym: _vt$12ItA_00202808 = 0x00366AC0 */
/* sym: _vt$12ItB_00202808 = 0x00366AA8 */
struct HA_00202808 {
    char pad0[0x24];
    unsigned char m24;
};

struct HB_00202808 {
    char pad0[0x18];
    unsigned char m18;
};

template <class T> struct Node_00202808 {
    int m0;
    T* m4;
    int m8;
    Node_00202808* mC;
    Node_00202808* Valid() { if (~(int)m4 == 0) return 0; return this; }
    T* GetData() { return m4; }
};

struct Owner_00202808 {
    char pad0[0x18];
    Node_00202808<HA_00202808> mA;
    char pad28[0x8];
    Node_00202808<HB_00202808> mB;
};

class ItA_00202808 {
public:
    int m0;
    Node_00202808<HA_00202808>* cur;
    ItA_00202808() { cur = 0; }
    virtual ~ItA_00202808() {}
    virtual void Run();
    HA_00202808* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    HA_00202808* Advance(Node_00202808<HA_00202808>* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    HA_00202808* First(Node_00202808<HA_00202808>* h)
    {
        cur = h;
        return Next();
    }
};

class ItB_00202808 {
public:
    int m0;
    Node_00202808<HB_00202808>* cur;
    ItB_00202808() { cur = 0; }
    virtual ~ItB_00202808() {}
    virtual void Run();
    HB_00202808* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    HB_00202808* First(Node_00202808<HB_00202808>* h)
    {
        cur = h;
        return Next();
    }
};

int func_00202808(Owner_00202808* o)
{
    ItA_00202808 a;
    ItB_00202808 b;
    int m = 0;
    HA_00202808* h = a.First(&o->mA);
    if (h) {
        ItA_00202808* p = &a;
        do {
            if (m < h->m24) m = h->m24;
            h = p->Advance(a.cur);
        } while (h);
    }
    for (HB_00202808* h = b.First(&o->mB); h; h = b.Next()) {
        if (m < h->m18) m = h->m18;
    }
    return m;
}
