struct Item_002A53F8;

struct Node_002A53F8 {
    int m0;
    Item_002A53F8* m4;
    int m8;
    Node_002A53F8* mC;
    Item_002A53F8* GetData() { return m4; }
    Node_002A53F8* Valid() { return (int)m4 != -1 ? this : 0; }
};

struct Iter_002A53F8 {
    int m0;
    Node_002A53F8* m4;
    Item_002A53F8* Next() {
        m4 = m4->mC->Valid();
        if (!m4)
            return 0;
        return m4->GetData();
    }
    Item_002A53F8* First(Node_002A53F8* head) {
        m4 = head;
        return Next();
    }
};

struct Table_002A53F8;
extern "C" int func_002B1FE8(Item_002A53F8* e);
extern "C" Item_002A53F8* func_002A5490(Table_002A53F8* t, Iter_002A53F8* it, int all);
extern "C" Item_002A53F8* func_002A53F8(Table_002A53F8* t, Iter_002A53F8* it, int all);

struct Table_002A53F8 {
    char pad[0xDC];
    Node_002A53F8 mDC;
};

extern "C" Item_002A53F8* func_002A53F8(Table_002A53F8* t, Iter_002A53F8* it, int all)
{
    Item_002A53F8* e = it->First(&t->mDC);
    if (!all && e && func_002B1FE8(e))
        e = func_002A5490(t, it, 0);
    return e;
}
