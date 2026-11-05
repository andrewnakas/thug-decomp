struct Item_0023F168 {
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
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual int V21();
};

struct Mgr_0023F168 {
    int m0;
    char m_4[0x18];
    void UpdateAll();
};

extern "C" int func_0023C040(Mgr_0023F168* self);
extern "C" Item_0023F168* func_00243C18(void* list, int* index, int* out);
extern "C" void func_00247D00(Item_0023F168* item);

void Mgr_0023F168::UpdateAll()
{
    int n = func_0023C040(this);
    int i;
    int tmp;
    for (i = 0; i < n; i++) {
        Item_0023F168* item = func_00243C18(m_4, &i, &tmp);
        if (item->V21()) {
            func_00247D00(item);
        }
    }
}
