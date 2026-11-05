struct Mgr_00220838 {
    char pad0[0x24];
    void* m_24;
    char pad28[0x84 - 0x28];
    void* m_84;
};

extern Mgr_00220838* D_0038FC78;
extern "C" void* func_00263930(void* a);
extern "C" void* func_0026EE60(void* a, void* b);
extern "C" void* func_0026EE38(void* a);
extern "C" void func_0026E9C0(void* a, void* b);

bool Cmd_00220838(void* params, void* script)
{
    void* x = func_00263930(D_0038FC78->m_24);
    void* p = D_0038FC78->m_84;
    void* y = func_0026EE60(p, x);
    func_0026E9C0(y, func_0026EE38(p));
    return true;
}
