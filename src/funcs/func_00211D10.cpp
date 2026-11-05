struct Mgr_00211D10 {
    char pad[0x28];
    void* m28;
};
extern Mgr_00211D10* D_0038FC78;
extern "C" void func_0026B728();
extern "C" void func_0026C1D8();
extern "C" void func_002683E8(void* p);
extern "C" void* func_0022E048(Mgr_00211D10* m);
extern "C" void func_00266100(void* p);
extern "C" void func_001362A0();
extern "C" void func_001362A8();

void func_00211D10()
{
    Mgr_00211D10* m = D_0038FC78;
    func_0026B728();
    func_0026C1D8();
    func_002683E8(m->m28);
    func_00266100(func_0022E048(m));
    func_001362A0();
    func_001362A8();
}
