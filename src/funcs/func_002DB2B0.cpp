extern char D_0037C9D0[];
extern char D_0037C9E8[];

struct Item_002DB2B0 {
    char pad[0x14];
    virtual ~Item_002DB2B0();
};

struct Node_002DB2B0 {
    int m0;
    Item_002DB2B0* data;
    int m8;
    Node_002DB2B0* next;
    Node_002DB2B0* prev;
    Item_002DB2B0* GetData() { return data; }
    Node_002DB2B0* Valid() { return (int)data != -1 ? this : 0; }
};

struct ItA_002DB2B0 {
    int m0;
    Node_002DB2B0* cur;
    void* vt;
    ItA_002DB2B0() { vt = D_0037C9D0; cur = 0; }
    ~ItA_002DB2B0() { vt = D_0037C9D0; }
    Item_002DB2B0* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_002DB2B0* Advance(Node_002DB2B0* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_002DB2B0* First(Node_002DB2B0* h) {
        cur = h;
        return Next();
    }
};

struct ItB_002DB2B0 {
    int m0;
    Node_002DB2B0* cur;
    void* vt;
    ItB_002DB2B0() { vt = D_0037C9E8; cur = 0; }
    ~ItB_002DB2B0() { vt = D_0037C9E8; }
    Item_002DB2B0* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_002DB2B0* First(Node_002DB2B0* h) {
        cur = h;
        return Next();
    }
};

struct Mgr_002DB2B0 : Node_002DB2B0 {
    int m14;
    Node_002DB2B0 m18;
    void Clear();
};

void Mgr_002DB2B0::Clear()
{
    ItA_002DB2B0 ia;
    ItB_002DB2B0 ib;
    Item_002DB2B0* d = ia.First(this);
    if (d) {
        ItA_002DB2B0* p = &ia;
        do {
            Item_002DB2B0* n = p->Advance(ia.cur);
            delete d;
            d = n;
        } while (d);
    }
    d = ib.First(&m18);
    while (d) {
        Item_002DB2B0* n = ib.Next();
        delete d;
        d = n;
    }
}
