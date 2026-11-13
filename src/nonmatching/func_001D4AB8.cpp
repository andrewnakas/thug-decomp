/* fuzzy: 89.4 */
// nm: 9 words: s1/s2 swap between result and the || temporary (lane 2 draft)
struct Item_001D4AB8 {
    char m_pad0[0xC];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual int Handle(int a, int b, int c, int d);
};

struct Node_001D4AB8 {
    int m0;
    Item_001D4AB8* m_item;
    int m8;
    Node_001D4AB8* m_next;
};

static inline Node_001D4AB8* Valid_001D4AB8(Node_001D4AB8* n)
{
    if (n->m_item == (Item_001D4AB8*)-1)
        return 0;
    return n;
}

struct List_001D4AB8 {
    char m_pad0[0xC];
    Node_001D4AB8* m_next;
};

struct Obj_001D4AB8 {
    char m_pad0[0x10];
    List_001D4AB8* m_list;
    bool Run(int a, int b, int c, int d);
};

bool Obj_001D4AB8::Run(int a, int b, int c, int d)
{
    bool result = false;
    for (Node_001D4AB8* n = Valid_001D4AB8(m_list->m_next); n; n = Valid_001D4AB8(n->m_next)) {
        result = n->m_item->Handle(a, b, c, d) || result;
    }
    return result;
}
