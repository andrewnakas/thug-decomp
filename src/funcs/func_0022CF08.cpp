struct Base_0022CF08 {
    int m0;
    int m4;
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
    virtual void Set(int index, int value);
};

struct Obj_0022CF08 : Base_0022CF08 {
    int pad[3];
    int m_18;
};

struct Mgr_0022CF08 {
    void Set(Obj_0022CF08* o, int index, int value);
};

extern "C" int func_0022CBF8(Mgr_0022CF08* self, int v);

void Mgr_0022CF08::Set(Obj_0022CF08* o, int index, int value)
{
    if (index == -1) {
        index = func_0022CBF8(this, o->m_18);
        if (index == -1) {
            return;
        }
    }
    o->Set(index, value);
}
