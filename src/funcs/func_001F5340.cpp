extern "C" void func_001F5D68(void* p);

struct Obj_001F5340 {
    char pad[0x48];
    int m_sub;
    void Run();
};

void Obj_001F5340::Run()
{
    func_001F5D68(&m_sub);
}
