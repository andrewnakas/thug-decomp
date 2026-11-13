/* sym: _vt$12ItA_001FF268 = 0x00366AC0 */
/* sym: _vt$12ItB_001FF268 = 0x00366AA8 */
struct HA_001FF268 {
    char pad0[0x18];
    int m18;
    int m1C;
    int m20;
};

struct HB_001FF268 {
    char pad0[0x1C];
    int m1C;
    int m20;
};

template <class T> struct Node_001FF268 {
    int m0;
    T* m4;
    int m8;
    Node_001FF268* mC;
    Node_001FF268* Valid() { if (~(int)m4 == 0) return 0; return this; }
    T* GetData() { return m4; }
};

struct Owner_001FF268 {
    char pad0[0x18];
    Node_001FF268<HA_001FF268> mA;
    char pad28[0x8];
    Node_001FF268<HB_001FF268> mB;
};

class ItA_001FF268 {
public:
    int m0;
    Node_001FF268<HA_001FF268>* cur;
    ItA_001FF268() { cur = 0; }
    virtual ~ItA_001FF268() {}
    virtual void Run();
    HA_001FF268* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    HA_001FF268* First(Node_001FF268<HA_001FF268>* h)
    {
        cur = h;
        return Next();
    }
};

class ItB_001FF268 {
public:
    int m0;
    Node_001FF268<HB_001FF268>* cur;
    ItB_001FF268() { cur = 0; }
    virtual ~ItB_001FF268() {}
    virtual void Run();
    HB_001FF268* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    HB_001FF268* First(Node_001FF268<HB_001FF268>* h)
    {
        cur = h;
        return Next();
    }
};

extern "C" unsigned int func_00202788(Owner_001FF268* o);

int func_001FF268(unsigned int* now, Owner_001FF268* o)
{
    {
        ItA_001FF268 a;
        HA_001FF268* h = a.First(&o->mA);
        while (h) {
            if (h->m18 == 0 || *now - h->m18 > func_00202788(o)) return 1;
            h = a.Next();
        }
    }
    {
        ItB_001FF268 b;
        HB_001FF268* h = b.First(&o->mB);
        while (h) {
            if (h->m20 == 0 || *now - h->m20 > func_00202788(o)) return 1;
            h = b.Next();
        }
    }
    return 0;
}
