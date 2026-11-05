struct Item_0023EED8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual void V0();
    virtual bool V1();
    virtual void V2();
    virtual bool V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual bool V8();
    virtual void V9();
    virtual void V10();
    virtual bool V11(int a, int b);
};

extern "C" Item_0023EED8* func_00243C18(void* list, int* i, int* out);
extern "C" bool func_00246740(Item_0023EED8* o);

struct Obj_0023EED8 {
    int m0;
    char m4[0x10];
    void Reset();
};

extern "C" int func_0023C040(Obj_0023EED8* self);

void Obj_0023EED8::Reset()
{
    int n = func_0023C040(this);
    for (int i = 0; i < n; i++) {
        int tmp;
        Item_0023EED8* o = func_00243C18(m4, &i, &tmp);
        if (func_00246740(o) && o->V3() && o->V8()) o->V11(0, 1);
    }
}
