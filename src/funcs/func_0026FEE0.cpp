extern "C" void* func_00185578(void* obj, unsigned int name);

struct Obj_0026FEE0 {
    char pad[0xC];
    void* mC;
    char pad2[0x2C - 0x10];
    void* m_comp;
    void Init();
};

void Obj_0026FEE0::Init()
{
    m_comp = func_00185578(mC, 0x5BD63B29);
}
