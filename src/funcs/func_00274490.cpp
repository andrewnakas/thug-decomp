extern "C" void* func_00185578(void* obj, unsigned int type);

struct Obj_00274490 {
    char pad0[0xC];
    void* m_obj;
    char pad10[0x29C];
    void* m_2AC;
    void* m_2B0;
    void* m_2B4;
    void* m_2B8;
    void* m_2BC;
    void* m_2C0;
    void* m_2C4;

    void GetComponents();
};

void Obj_00274490::GetComponents()
{
    m_2AC = func_00185578(m_obj, 0x18223FD6);
    m_2B8 = func_00185578(m_obj, 0x43686585);
    m_2BC = func_00185578(m_obj, 0xB1D5A3E1);
    m_2B0 = func_00185578(m_obj, 0x72AD7B23);
    m_2C0 = func_00185578(m_obj, 0x488AF07A);
    m_2B4 = func_00185578(m_obj, 0x286A8D26);
    m_2C4 = func_00185578(m_obj, 0x8A897DD2);
}
