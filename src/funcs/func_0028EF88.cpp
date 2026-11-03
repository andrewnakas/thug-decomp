extern "C" void* func_00185578(void*, unsigned int);

struct Obj_0028EF88 {
    char pad0[0xC];
    void* m_node;
    char pad1[0x24 - 0x10];
    void* m24;
    void* m28;
    void* m2C;
    void* m30;
    void* m34;
    void Init();
};

void Obj_0028EF88::Init()
{
    m24 = func_00185578(m_node, 0x5BD63B29);
    m28 = func_00185578(m_node, 0x286A8D26);
    m2C = func_00185578(m_node, 0x8A897DD2);
    m30 = func_00185578(m_node, 0x408D2AA9);
    m34 = func_00185578(m_node, 0x43686585);
}
