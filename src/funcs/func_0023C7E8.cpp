class Node_0023C7E8 {
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

struct Graph_0023C7E8 {
    int m0;
    char m4[4];
};

extern "C" int func_0023C040(Graph_0023C7E8* g);
extern "C" Node_0023C7E8* func_00243C18(void* list, int* i, int* j);
extern "C" bool func_00246C60(Node_0023C7E8* n);
extern "C" bool func_00246740(Node_0023C7E8* n);

extern "C" void func_0023C7E8(Graph_0023C7E8* g)
{
    int i;
    int j;
    for (i = 0; i < func_0023C040(g); i++) {
        Node_0023C7E8* n = func_00243C18(g->m4, &i, &j);
        if (n->IsActive() && !func_00246C60(n) && !func_00246740(n)) {
            n->Trigger(0, 1);
            return;
        }
    }
}
