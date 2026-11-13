/* force: {"kind": "ga", "before": [118, 233]} */
extern char D_0037C9D0[];
extern char D_0037C9E8[];

struct Data_002DA7A8;

struct Node_002DA7A8 {
    int m0;
    Data_002DA7A8* data;
    int m8;
    Node_002DA7A8* next;
    Node_002DA7A8* prev;
    Data_002DA7A8* GetData() { return data; }
    Node_002DA7A8* Valid() { return data == (Data_002DA7A8*)-1 ? 0 : this; }
};

struct List_002DA7A8 : Node_002DA7A8 {
    int Count()
    {
        int n = 0;
        for (Node_002DA7A8* x = next->Valid(); x; x = x->next->Valid()) n++;
        return n;
    }
};

struct Data_002DA7A8 {
    char pad[0x1C];
    List_002DA7A8 m1C;
};

struct ItA_002DA7A8 {
    int m0;
    Node_002DA7A8* cur;
    void* vt;
    ItA_002DA7A8() { vt = D_0037C9D0; cur = 0; }
    ~ItA_002DA7A8() { vt = D_0037C9D0; }
    Data_002DA7A8* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002DA7A8* First(Node_002DA7A8* h) {
        cur = h;
        return Next();
    }
};

struct ItB_002DA7A8 {
    int m0;
    Node_002DA7A8* cur;
    void* vt;
    ItB_002DA7A8() { vt = D_0037C9E8; cur = 0; }
    ~ItB_002DA7A8() { vt = D_0037C9E8; }
    Data_002DA7A8* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002DA7A8* First(Node_002DA7A8* h) {
        cur = h;
        return Next();
    }
};

struct Mgr_002DA7A8 : Node_002DA7A8 {
    int m14;
    Node_002DA7A8 m18;
    int Count(int max);
};

int Mgr_002DA7A8::Count(int max)
{
    int total = 0;
    ItA_002DA7A8 ia;
    ItB_002DA7A8 ib;
    Data_002DA7A8* d;
    for (d = ia.First(this); d; d = ia.Next()) {
        total += d->m1C.Count() > max ? max : d->m1C.Count();
    }
    for (d = ib.First(&m18); d; d = ib.Next()) {
        total++;
    }
    return total;
}
