struct Mgr_0022E2E8 {
    char pad0[0x28];
    void* m_28;
    char pad2C[0x78 - 0x2C];
    void* m_78;
    void Shutdown();
};

extern "C" void func_00266100(void* a);
extern "C" void func_00143608();
extern "C" void func_00141390();
extern "C" void func_002683E8(void* a);
extern "C" void func_0026B770();
extern "C" void func_0026C228();

void Mgr_0022E2E8::Shutdown()
{
    func_00266100(m_78);
    func_00143608();
    func_00141390();
    func_002683E8(m_28);
    func_0026B770();
    func_0026C228();
}
