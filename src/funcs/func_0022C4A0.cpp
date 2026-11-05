struct Obj_0022C4A0 {
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
    virtual void Enable();
    virtual void Disable();
};

struct Mgr_0022C4A0 {
    void SetEnabled(Obj_0022C4A0* o, bool on);
};

extern "C" void func_00185128(Obj_0022C4A0* o, bool on);

void Mgr_0022C4A0::SetEnabled(Obj_0022C4A0* o, bool on)
{
    if (on) {
        o->Enable();
    } else {
        o->Disable();
    }
    func_00185128(o, on);
}
