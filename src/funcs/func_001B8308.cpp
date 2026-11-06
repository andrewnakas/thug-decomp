extern "C" void* func_00185578(void* p, unsigned int id);
struct Obj_001B8308 {
    int m0, m4, m8;
    void* mC;
    char pad[0x160 - 0x10];
    void* m160;
    void Init();
};

void Obj_001B8308::Init()
{
    m160 = func_00185578(mC, 0x81C7122D);
}
