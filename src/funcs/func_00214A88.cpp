struct Node_00214A88 {
    int m0;
    int m4;
    int m8;
    Node_00214A88* mC;
    Node_00214A88* Valid() { if (~m4 == 0) return 0; return this; }
    unsigned int Count()
    {
        unsigned int n = 0;
        for (Node_00214A88* p = mC->Valid(); p; p = p->mC->Valid()) n++;
        return n;
    }
};

struct Base_00214A88 {
    int m0;
    int m4;
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
    virtual void Reset();
};

struct Game_00214A88 {
    char pad0[0x30];
    Node_00214A88 m_list;
};

extern Game_00214A88* D_0038FC78;
extern "C" Base_00214A88* func_0022DE70(Game_00214A88* g, unsigned int i);
extern "C" void func_00185128(Base_00214A88* o, int a);

bool func_00214A88(void* params, void* script)
{
    Game_00214A88* g = D_0038FC78;
    unsigned int n = g->m_list.Count();
    for (unsigned int i = 0; i < n; i++) {
        Base_00214A88* o = func_0022DE70(g, i);
        if (o) {
            o->Reset();
            func_00185128(o, 0);
        }
    }
    return true;
}
