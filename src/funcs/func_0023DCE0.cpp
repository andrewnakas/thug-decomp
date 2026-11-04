struct Link_0023DCE0 {
    int m0;
};

class Base_0023DCE0 {
public:
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual bool Check();
};

class Node_0023DCE0 : public Base_0023DCE0 {
public:
    char pad18[0x30 - 0x18];
    Link_0023DCE0* m30;
};

struct Graph_0023DCE0 {
    int m0;
    char m4[4];
};

extern "C" int func_0023C040(Graph_0023DCE0* g);
extern "C" Node_0023DCE0* func_00243C18(void* list, int* i, int* j);

extern "C" int func_0023DCE0(Graph_0023DCE0* g)
{
    int n = 0;
    int i;
    int j;
    for (i = 0; i < func_0023C040(g); i++) {
        Node_0023DCE0* x = func_00243C18(g->m4, &i, &j);
        if (!x->m30->m0 && x->Check()) n++;
    }
    return n;
}
