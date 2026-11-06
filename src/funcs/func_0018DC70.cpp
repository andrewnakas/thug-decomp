class Comp_0018DC70 {
public:
    char pad0[0x18];
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
    virtual void V11(void* a, int b, int c, void* d);
};

class Obj_0018DC70 : public Comp_0018DC70 {
public:
    char pad1C[0x260 - 0x1C];
    void* m260;
    void Fn(void* a, void* d);
};

void Obj_0018DC70::Fn(void* a, void* d)
{
    if (m260)
        V11(a, 1, 0, d);
}
