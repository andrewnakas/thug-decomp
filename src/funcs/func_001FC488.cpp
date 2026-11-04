/* sym: _vt$11It_001FC488 = 0x00366A48 */
struct Node_001FC488;

struct Event_001FC488 {
    char pad0[4];
    unsigned char m4;
    char pad5[0x18 - 5];
    int m18;
    int m1C;
};

struct Handler_001FC488 {
    char pad0[0x18];
    int (*m18)(Event_001FC488* e);
    int m1C;
    int m20;
};

struct Node_001FC488 {
    int m0;
    Handler_001FC488* m4;
    int m8;
    Node_001FC488* mC;
    int m10;
    int m14;
    Node_001FC488* Valid() { if (~(int)m4 == 0) return 0; return this; }
    Handler_001FC488* GetData() { return m4; }
};

class It_001FC488 {
public:
    int m0;
    Node_001FC488* cur;
    It_001FC488() {}
    virtual ~It_001FC488() {}
    virtual void Run();
    Handler_001FC488* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Handler_001FC488* Advance(Node_001FC488* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Handler_001FC488* First(Node_001FC488* h)
    {
        cur = h;
        return Next();
    }
};

int func_001FC488(Node_001FC488* table, Event_001FC488* e)
{
    It_001FC488 it;
    Handler_001FC488* h = it.First(&table[e->m4]);
    if (h) {
    It_001FC488* p = &it;
    do {
        Handler_001FC488* next = p->Advance(it.cur);
        if ((h->m20 & e->m18) == e->m18) {
            e->m1C = h->m1C;
            int r = h->m18(e);
            if (r == 0 || r == 2 || r == 4) return r;
            if (r == 3) return 1;
        }
        h = next;
    } while (h);
    }
    return 1;
}
