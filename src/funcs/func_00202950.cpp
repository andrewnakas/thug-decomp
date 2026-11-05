/* sym: _vt$12ItB_00202950 = 0x00366AA8 */
struct HB_00202950 {
    char pad0[0x1A];
    signed char m1A;
};

struct Node_00202950 {
    int m0;
    HB_00202950* m4;
    int m8;
    Node_00202950* mC;
    Node_00202950* Valid() { if (~(int)m4 == 0) return 0; return this; }
    HB_00202950* GetData() { return m4; }
};

struct Owner_00202950 {
    char pad0[0x30];
    Node_00202950 m30;
};

class ItB_00202950 {
public:
    int m0;
    Node_00202950* cur;
    ItB_00202950() { cur = 0; }
    virtual ~ItB_00202950() {}
    virtual void Run();
    HB_00202950* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    HB_00202950* Advance(Node_00202950* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    HB_00202950* First(Node_00202950* h)
    {
        cur = h;
        return Next();
    }
};

extern "C" int func_00202950(Owner_00202950* o)
{
    ItB_00202950 it;
    int n = 0;
    HB_00202950* h = it.First(&o->m30);
    if (h) {
        ItB_00202950* p = &it;
        do {
            if (h->m1A) n++;
            h = p->Advance(it.cur);
        } while (h);
    }
    return n;
}
