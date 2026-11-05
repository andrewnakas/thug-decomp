struct Node_0025F3F0 {
    char pad[0x14];
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual int Va();
};

struct Item_0025F3F0 : Node_0025F3F0 {
    void* m18;
};

struct Obj_0025F3F0;
extern "C" Item_0025F3F0* func_0025F128(Obj_0025F3F0* l, int i);

struct Obj_0025F3F0 {
    char pad[0x60];
    char m60[0xC4];
    int m124;
    void* Fn();
};

void* Obj_0025F3F0::Fn()
{
    Item_0025F3F0* n = func_0025F128(this, 0);
    if (n && n->Va()) return n->m18;
    if (m124) return m60;
    return 0;
}
