struct Item_0023BE68 {
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
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual int V14();
};

struct Mgr_0023BE68 {
    bool Call(int id);
};

extern "C" Item_0023BE68* func_0023BAD8(Mgr_0023BE68* self, int id, int create);

bool Mgr_0023BE68::Call(int id)
{
    Item_0023BE68* item = func_0023BAD8(this, id, 1);
    if (item) {
        item->V14();
    }
    return item != 0;
}
