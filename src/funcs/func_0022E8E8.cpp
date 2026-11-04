struct Node_0022E8E8 {
    int m0;
    int m4;
    int m8;
    Node_0022E8E8* mC;
    Node_0022E8E8* Valid() { if (~m4 == 0) return 0; return this; }
    unsigned int Count()
    {
        unsigned int n = 0;
        for (Node_0022E8E8* p = mC->Valid(); p; p = p->mC->Valid()) n++;
        return n;
    }
};

struct Item_0022E8E8 {
    char pad0[0x31C];
    int m31C;
};

struct Mgr_0022E8E8;
extern "C" Item_0022E8E8* func_0022DE70(Mgr_0022E8E8* self, unsigned int i);
extern "C" void func_0022CF08(Mgr_0022E8E8* self, Item_0022E8E8* it, int a, int b);
extern "C" void func_00206920(Item_0022E8E8* it);

struct Mgr_0022E8E8 {
    char pad0[0x30];
    Node_0022E8E8 m_list;
    char pad40[0x28];
    int m68;

    void UpdateAll(int a, int b);
};

void Mgr_0022E8E8::UpdateAll(int a, int b)
{
    Node_0022E8E8* list = &m_list;
    for (unsigned int i = 0; i < list->Count(); i++) {
        Item_0022E8E8* it = func_0022DE70(this, i);
        if (it->m31C) func_0022CF08(this, it, a, b);
        func_00206920(it);
    }
    m68 = 0;
}
