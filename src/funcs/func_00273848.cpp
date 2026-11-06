extern "C" void* func_00185578(void* obj, unsigned int name);

struct Obj_00273848 {
    char pad[0xC];
    void* mC;
    char pad2[0x40 - 0x10];
    void* m40;
    void* m44;
    void Init();
};

void Obj_00273848::Init()
{
    m40 = func_00185578(mC, 0x43686585);
    m44 = func_00185578(mC, 0x5BD63B29);
}
