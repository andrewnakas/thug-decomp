struct Item_0023BC10 {
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
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual int V22();
};

struct Mgr_0023BC10 {
    char pad[0x20];
    int m_20;
    int Select(int id, int flag);
};

extern "C" Item_0023BC10* func_0023BAD8(Mgr_0023BC10* self, int id, int create);

int Mgr_0023BC10::Select(int id, int flag)
{
    int r = 0;
    Item_0023BC10* item = func_0023BAD8(this, id, 1);
    if (!item && flag) {
        return 0;
    }
    if (item) {
        r = item->V9();
        if (r && item->V22()) {
            m_20 = id;
        }
    }
    return r;
}
