struct Comp_0022D2D0 {
    char pad[0x13F8];
    int m_13F8;
};

struct Mgr_0022D2D0 {
    char pad[0x398];
    void* m_398;
    int Get();
};

extern "C" int func_00252270(void* obj);
extern "C" void* func_0022DF08(Mgr_0022D2D0* self, int index);
extern "C" Comp_0022D2D0* func_00185578(void* obj, unsigned int name);

int Mgr_0022D2D0::Get()
{
    return func_00185578(func_0022DF08(this, func_00252270(m_398)), 0x270F56E1)->m_13F8;
}
