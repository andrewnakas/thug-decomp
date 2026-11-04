struct Item_002A5628 {
    char pad[0x14];
    void* m14;
};

struct Node_002A5628 {
    int m0;
    Item_002A5628* m4;
    int m8;
    Node_002A5628* mC;
    int m10;
    virtual ~Node_002A5628();
    Node_002A5628* Valid() { return (int)m4 != -1 ? this : 0; }
};

extern "C" void func_00200F28(void* a, void* b);
extern "C" void func_002B3168(Item_002A5628* it, int flags);

struct Obj_002A5628 {
    char pad[0x14];
    void* m14;
    void* m18;
    char pad2[0x100 - 0x1C];
    Node_002A5628* m100;
    void Remove(Item_002A5628* item);
};

void Obj_002A5628::Remove(Item_002A5628* item)
{
    for (Node_002A5628* n = m100->Valid(); n; n = n->mC->Valid()) {
        Item_002A5628* it = n->m4;
        if (it == item) {
            if (m14)
                func_00200F28(m14, it->m14);
            else if (it->m14)
                func_00200F28(m18, it->m14);
            delete n;
            if (it)
                func_002B3168(it, 3);
            return;
        }
    }
}
