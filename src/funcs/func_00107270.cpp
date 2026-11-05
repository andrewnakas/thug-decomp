/* sym: _vt$11It_00107270 = 0x0035AE38 */
struct Node_00107270 {
    int m0;
    void* m4;
    int m8;
    Node_00107270* mC;
    Node_00107270* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

class It_00107270 {
public:
    int m0;
    Node_00107270* cur;
    It_00107270() {}
    virtual ~It_00107270() {}
    virtual void Run();
    void* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* Advance(Node_00107270* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* First(Node_00107270* h)
    {
        cur = h;
        return Next();
    }
};

struct Item_00107270 {
    char pad[0xE4];
    int mE4;
};

struct Owner_00107270 {
    int m0;
    Node_00107270 m_list;
    Item_00107270* Find(int id);
};

Item_00107270* Owner_00107270::Find(int id)
{
    It_00107270 it;
    for (Item_00107270* d = (Item_00107270*)it.First(&m_list); d; d = (Item_00107270*)it.Next()) {
        if (d->mE4 == id) {
            return d;
        }
    }
    return 0;
}
