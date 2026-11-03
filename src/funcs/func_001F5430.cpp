extern "C" void func_001F6558(void* p);

struct Obj_001F5430 {
    char pad[0x48];
    int m_sub;
    void Run();
};

void Obj_001F5430::Run()
{
    func_001F6558(&m_sub);
}
