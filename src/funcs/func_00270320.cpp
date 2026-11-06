extern "C" void* func_00185578(void* obj, unsigned int name);

struct Obj_00270320 {
    char pad[0xC];
    void* mC;
    char pad2[0x4C - 0x10];
    void* m_comp;
    void Init();
};

void Obj_00270320::Init()
{
    m_comp = func_00185578(mC, 0xD9151D4D);
}
