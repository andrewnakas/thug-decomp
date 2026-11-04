extern "C" int func_0023C040(void* self);
extern "C" void* func_00243C18(void* list, int* idx, int* out);
extern "C" int func_002464B0(void* o, int a);

struct Item_0023D6A8 {
    char pad0[0x14];
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
    virtual int IsActive();
};

struct Obj_0023D6A8 {
    int m0;
    char m_4[0x3C];
    bool Has(int a);
};

bool Obj_0023D6A8::Has(int a)
{
    for (int i = 0; i < func_0023C040(this); i++) {
        int tmp;
        Item_0023D6A8* o = (Item_0023D6A8*)func_00243C18(m_4, &i, &tmp);
        if (o->IsActive() && func_002464B0(o, a)) {
            return true;
        }
    }
    return false;
}
