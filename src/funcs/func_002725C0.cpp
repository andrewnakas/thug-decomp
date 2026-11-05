extern "C" void* func_00185578(void* obj, unsigned int name);

struct Obj_002725C0 {
    char pad[0xC];
    void* mC;
    char pad2[0x58 - 0x10];
    void* m_comp;
    void Init();
};

void Obj_002725C0::Init()
{
    m_comp = func_00185578(mC, 0x5BD63B29);
}
