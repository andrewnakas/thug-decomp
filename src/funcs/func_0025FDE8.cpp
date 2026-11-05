struct Node_0025FDE8 {
    char pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual int V9();
};

struct List_0025FDE8;
extern "C" Node_0025FDE8* func_0025F128(List_0025FDE8* l, int i);

struct List_0025FDE8 {
    int Fn();
};

int List_0025FDE8::Fn()
{
    Node_0025FDE8* n = func_0025F128(this, 0);
    if (n) return n->V9();
    return 1;
}
