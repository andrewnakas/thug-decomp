struct Comp_0022D250 {
    char pad[0x13F4];
    int m_13F4;
};

struct Mgr_0022D250 {
    char pad[0x398];
    void* m_398;
    int Check();
};

extern "C" int func_00252270(void* obj);
extern "C" void* func_0022DF08(Mgr_0022D250* self, int index);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_00290720(void* obj, int v);

int Mgr_0022D250::Check()
{
    void* obj = func_0022DF08(this, func_00252270(m_398));
    Comp_0022D250* c = (Comp_0022D250*)func_00185578(obj, 0x270F56E1);
    if (c->m_13F4) {
        func_00290720(func_00185578(obj, 0xB1D5A3E1), 0);
    }
    return c->m_13F4;
}
