class Node_0023C298 {
public:
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool IsActive();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual bool Trigger(int a, int b);
};

struct Graph_0023C298 {
    int m0;
    char m4[4];
};

extern "C" int func_0023C040(Graph_0023C298* g);
extern "C" Node_0023C298* func_00243C18(void* list, int* i, int* j);
extern "C" void func_0023C298(Graph_0023C298* g, int a)
{
    int i;
    int j;
    for (i = 0; i < func_0023C040(g); i++) {
        Node_0023C298* n = func_00243C18(g->m4, &i, &j);
        if (n->IsActive()) n->Trigger(a, 1);
    }
}
