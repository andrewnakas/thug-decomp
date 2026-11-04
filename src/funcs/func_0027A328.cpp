struct Comp_0027A328 {
    char pad0[0xC];
    void* m_object;
    char pad10[0x594 - 0x10];
    void* m594;
    void* m598;
    void* m59C;
    void* m5A0;
    void* m5A4;
    void* m5A8;
    void* m5AC;
    void* m5B0;
    void* m5B4;
    void* m5B8;
    void* m5BC;
    void Finalize();
};

extern "C" void* func_00185578(void* obj, unsigned int name);

void Comp_0027A328::Finalize()
{
    m594 = func_00185578(m_object, 0x27D7CD28);
    m59C = func_00185578(m_object, 0x187574FA);
    m598 = func_00185578(m_object, 0xE594F0A2);
    m5A0 = func_00185578(m_object, 0x270F56E1);
    m5A4 = func_00185578(m_object, 0x52D61A0D);
    m5A8 = func_00185578(m_object, 0xD262802F);
    m5AC = func_00185578(m_object, 0x589E5FB3);
    m5B0 = func_00185578(m_object, 0x43686585);
    m5B4 = func_00185578(m_object, 0x408D2AA9);
    m5B8 = func_00185578(m_object, 0xD9151D4D);
    m5BC = func_00185578(m_object, 0x726E85AA);
}
