extern char D_00366B10[];

struct Item_00201338 {
    char pad[0x18];
    int m18;
};

struct Node_00201338 {
    int m0;
    Item_00201338* data;
    int m8;
    Node_00201338* m_next;
    Node_00201338* Valid() { return (int)data != -1 ? this : 0; }
    Item_00201338* GetData() { return data; }
};

struct It_00201338 {
    int m0;
    Node_00201338* cur;
    void* vt;
    It_00201338() { vt = D_00366B10; }
    ~It_00201338() { vt = D_00366B10; }
    Item_00201338* Next()
    {
        cur = cur->m_next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Item_00201338* First(Node_00201338* h)
    {
        cur = h;
        return Next();
    }
};

struct Key_00201338 {
    char pad[0x4C];
    int m4C;
};

struct Obj_00201338 {
    char pad[0x42F0];
    Node_00201338 m_list;
    bool Has(Key_00201338* k);
};

bool Obj_00201338::Has(Key_00201338* k)
{
    It_00201338 it;
    for (Item_00201338* d = it.First(&m_list); d; d = it.Next()) {
        if (d->m18 == k->m4C)
            return true;
    }
    return false;
}
