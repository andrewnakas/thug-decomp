class Comp_00185238 {
public:
    char pad0[0x10];
    Comp_00185238* m10;
    char pad14[0x18 - 0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
};

struct Obj_00185238 {
    char pad0[0x100];
    Comp_00185238* m100;
    void Fn();
};

void Obj_00185238::Fn()
{
    for (Comp_00185238* c = m100; c; c = c->m10)
        c->V8();
}
