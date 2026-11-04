extern char D_00366AA8[];
extern char D_00366AC0[];

struct ItemA_00202A00 {
    char pad[0x24];
    unsigned char m_24;
};

struct ItemB_00202A00 {
    char pad[0x18];
    unsigned char m_18;
};

template <class T>
struct Node_00202A00 {
    int m0;
    T* data;
    int m8;
    Node_00202A00* next;
    int m10;
    int m14;
    T* GetData() { return data; }
    Node_00202A00* Valid() { return (int)data != -1 ? this : 0; }
};

struct ItA_00202A00 {
    int m0;
    Node_00202A00<ItemA_00202A00>* cur;
    void* vt;
    ItA_00202A00() { vt = D_00366AC0; cur = 0; }
    ~ItA_00202A00() { vt = D_00366AC0; }
    ItemA_00202A00* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    ItemA_00202A00* Advance(Node_00202A00<ItemA_00202A00>* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    ItemA_00202A00* First(Node_00202A00<ItemA_00202A00>* h) {
        cur = h;
        return Next();
    }
};

struct ItB_00202A00 {
    int m0;
    Node_00202A00<ItemB_00202A00>* cur;
    void* vt;
    ItB_00202A00() { vt = D_00366AA8; cur = 0; }
    ~ItB_00202A00() { vt = D_00366AA8; }
    ItemB_00202A00* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    ItemB_00202A00* First(Node_00202A00<ItemB_00202A00>* h) {
        cur = h;
        return Next();
    }
};

struct Obj_00202A00 {
    char pad[0x18];
    Node_00202A00<ItemA_00202A00> m_a;
    Node_00202A00<ItemB_00202A00> m_b;
    void Reset();
};

void Obj_00202A00::Reset()
{
    ItA_00202A00 ia;
    ItB_00202A00 ib;
    ItemA_00202A00* a = ia.First(&m_a);
    if (a) {
        ItA_00202A00* p = &ia;
        do {
            a->m_24 = 0;
            a = p->Advance(ia.cur);
        } while (a);
    }
    ItemB_00202A00* b = ib.First(&m_b);
    while (b) {
        b->m_18 = 0;
        b = ib.Next();
    }
}
