/* sym: _vt$11It_001071B8 = 0x0035AE38 */
struct Node_001071B8 {
    int m0;
    void* m4;
    int m8;
    Node_001071B8* mC;
    Node_001071B8* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

class It_001071B8 {
public:
    int m0;
    Node_001071B8* cur;
    It_001071B8() {}
    virtual ~It_001071B8() {}
    virtual void Run();
    void* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* Advance(Node_001071B8* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* First(Node_001071B8* h)
    {
        cur = h;
        return Next();
    }
};

struct Item_001071B8 {
    char pad[0x10];
    int m10;
    int m14;
};

struct Owner_001071B8 {
    int m0;
    Node_001071B8 m_list;
    Item_001071B8* Find(int a, int b);
};

Item_001071B8* Owner_001071B8::Find(int a, int b)
{
    It_001071B8 it;
    for (Item_001071B8* d = (Item_001071B8*)it.First(&m_list); d; d = (Item_001071B8*)it.Next()) {
        if (d->m10 == a && d->m14 == b) {
            return d;
        }
    }
    return 0;
}
