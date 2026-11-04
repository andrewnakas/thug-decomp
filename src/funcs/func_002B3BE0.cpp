extern char D_00379E70[];

struct Item_002B3BE0 {
    char pad[0xA0];
    int mA0;
};

struct Node_002B3BE0 {
    int m0;
    Item_002B3BE0* data;
    int m8;
    Node_002B3BE0* next;
    Item_002B3BE0* GetData() { return data; }
    Node_002B3BE0* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002B3BE0 {
    int m0;
    Node_002B3BE0* cur;
    void* vt;
    It_002B3BE0() { vt = D_00379E70; }
    ~It_002B3BE0() { vt = D_00379E70; }
    Item_002B3BE0* Advance(Node_002B3BE0* c)
    {
        cur = c->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Item_002B3BE0* First(Node_002B3BE0* h)
    {
        cur = h;
        return Advance(cur);
    }
};

struct Obj_002B3BE0 {
    char pad[0x124];
    Node_002B3BE0 m124;
    void Reset();
};

void Obj_002B3BE0::Reset()
{
    It_002B3BE0 it;
    Item_002B3BE0* d = it.First(&m124);
    if (d) {
        It_002B3BE0* p = &it;
        do {
            d->mA0 = 0;
            d = p->Advance(it.cur);
        } while (d);
    }
}
