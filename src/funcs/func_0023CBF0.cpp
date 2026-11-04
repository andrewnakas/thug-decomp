class Obj_0023CBF0 {
public:
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
    virtual int IsActive();
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
    virtual int IsReady();
};

extern "C" Obj_0023CBF0* func_0023BAD8(void* mgr, int id, int a);
extern "C" void func_00246BE8(Obj_0023CBF0* o);
extern "C" void func_00246C10(Obj_0023CBF0* o);

struct Self_0023CBF0 {
    char pad0[0x20];
    int m20;

    int Check(int id, int strict);
};

int Self_0023CBF0::Check(int id, int strict)
{
    Obj_0023CBF0* o = func_0023BAD8(this, id, 1);
    if (!o && strict)
        return 0;
    func_00246BE8(o);
    int r = o->IsActive();
    if (r && o->IsReady())
        m20 = id;
    func_00246C10(o);
    return r;
}
