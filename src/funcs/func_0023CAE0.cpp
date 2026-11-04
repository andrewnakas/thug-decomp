struct Item_0023CAE0 {
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
};

extern "C" Item_0023CAE0* func_00243C18(void* list, int* i, int* out);
extern "C" int func_00245448(Item_0023CAE0* o);

struct Obj_0023CAE0 {
    int m0;
    char m4[0x10];
    int Find();
};

extern "C" int func_0023C040(Obj_0023CAE0* self);

int Obj_0023CAE0::Find()
{
    int i = 0;
    while (i < func_0023C040(this)) {
        int tmp;
        Item_0023CAE0* o = func_00243C18(m4, &i, &tmp);
        if (o->V3() && o->V8() && !o->V1()) {
            int r = func_00245448(o);
            if (r < 0) return 0;
            return r;
        }
        i++;
    }
    return 0;
}
