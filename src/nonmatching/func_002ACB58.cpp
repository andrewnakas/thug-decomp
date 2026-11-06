/* fuzzy: 89.7 */
struct Item_002ACB58 {
    char pad[0x14];
    void* m14;
    void* m18;
};

struct Node_002ACB58 {
    int m0;
    Item_002ACB58* m4;
    int m8;
    Node_002ACB58* mC;
    int m10;
    virtual ~Node_002ACB58();
};

static inline Node_002ACB58* Valid_002ACB58(Node_002ACB58* n)
{
    if ((int)n->m4 != -1)
        return n;
    return 0;
}

struct Mgr_002ACB58 {
    char pad[0x100];
    Node_002ACB58* m100;
};

extern void* D_0038FC78;
extern "C" Item_002ACB58* func_002A5248(Mgr_002ACB58* s, void* id);
extern "C" int func_002B1FE8(Item_002ACB58* e);
extern "C" int func_002B1FC8(Item_002ACB58* e);
extern "C" void func_002A5A88(Mgr_002ACB58* m, Item_002ACB58* s, int a);
extern "C" void func_0022CF98(void* a, void* b);
extern "C" void func_00200F28(void* a, void* b);
extern "C" void func_002B3168(Item_002ACB58* it, int flags);

struct Obj_002ACB58 {
    char pad[0x10];
    void* m10;
    void* m14;
    char pad18[4];
    Mgr_002ACB58* m1C;
    int Handle();
};

int Obj_002ACB58::Handle()
{
    Mgr_002ACB58* mgr = m1C;
    void* g = D_0038FC78;
    Item_002ACB58* it = func_002A5248(mgr, m14);
    if (it) {
        if (!func_002B1FC8(it)) {
            void* x = it->m18;
            int r = func_002B1FE8(it);
            func_002A5A88(mgr, it, 0);
            if (!r)
                func_0022CF98(g, x);
        }
        return 4;
    }
    Node_002ACB58* node = Valid_002ACB58(mgr->m100);
    while (node) {
        Item_002ACB58* item = node->m4;
        Node_002ACB58* next = Valid_002ACB58(node->mC);
        if (item->m14 == m14) {
            func_00200F28(m10, item->m14);
            delete node;
            if (item)
                func_002B3168(item, 3);
            return 4;
        }
        node = next;
    }
    return 2;
}
