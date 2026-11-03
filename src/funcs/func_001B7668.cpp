extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void* func_001046B0(int size);
extern "C" void* func_00268380(void* mem);
extern "C" void func_002683A0(void* p, int flags);
extern "C" void func_0026AE08(void* p, int v);

struct Comp_001B7668 {
    int m_base[6];
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
    virtual int GetId();
};

struct C_001B7668 {
    int m_pad[3];
    void* mC;
    int m10[3];
    void* m1C;
    void Rebuild();
};

void C_001B7668::Rebuild()
{
    Comp_001B7668* c = (Comp_001B7668*)func_00185578(mC, 0xC472ECC5);
    if (m1C) func_002683A0(m1C, 3);
    m1C = func_00268380(func_001046B0(0x70));
    func_0026AE08(m1C, c->GetId());
}
