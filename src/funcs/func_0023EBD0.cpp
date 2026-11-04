class Obj_0023EBD0 {
public:
    char pad0[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int IsReady();
};

struct Self_0023EBD0;
extern "C" int func_0023C040(Self_0023EBD0* s);
extern "C" Obj_0023EBD0* func_00243C18(void* table, int* idx, int* pos);
extern "C" int func_00246C88(Obj_0023EBD0* o);

struct Self_0023EBD0 {
    int m0;
    char m4[0x1C];

    Obj_0023EBD0* FindReady();
};

Obj_0023EBD0* Self_0023EBD0::FindReady()
{
    int i = 0;
    while (i < func_0023C040(this)) {
        int pos;
        Obj_0023EBD0* o = func_00243C18(m4, &i, &pos);
        if (func_00246C88(o) && o->IsReady())
            return o;
        i++;
    }
    return 0;
}
