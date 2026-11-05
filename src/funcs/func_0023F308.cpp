struct Item_0023F308 {
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
    virtual int V17();
};

struct Mgr_0023F308 {
    int m0;
    char m_4[0x18];
    void* Collect();
};

extern "C" int func_0023C040(Mgr_0023F308* self);
extern "C" Item_0023F308* func_00243C18(void* list, int* index, int* out);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" int func_00246740(Item_0023F308* item);
extern "C" int func_00246C60(Item_0023F308* item);
extern "C" int func_00248380(Item_0023F308* item);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

void* Mgr_0023F308::Collect()
{
    int total = 0;
    int n = func_0023C040(this);
    void* s = func_001E6978(func_001190D0(8));
    int i;
    int tmp;
    for (i = 0; i < n; i++) {
        Item_0023F308* item = func_00243C18(m_4, &i, &tmp);
        if (!func_00246740(item) && !func_00246C60(item) && item->V17()) {
            total += func_00248380(item);
        }
    }
    func_001E7200(s, 0xD023ADBE, total);
    return s;
}
