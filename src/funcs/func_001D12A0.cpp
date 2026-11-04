extern "C" void func_00115D58(void* p, int n);

struct Obj_001D12A0 {
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
    virtual void V10(int a);
    virtual void* V11();
    int Run();
};

int Obj_001D12A0::Run()
{
    if (V11()) {
        void* p = V11();
        if (p) func_00115D58(p, 3);
        V10(0);
    }
    return 0;
}
