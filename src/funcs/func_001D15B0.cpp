struct Obj_001D15B0 {
    char pad[0x20];
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
    virtual void* V11();
    void* Run();
};

extern "C" void* func_0025D770(void* p);

void* Obj_001D15B0::Run()
{
    return func_0025D770(V11());
}
