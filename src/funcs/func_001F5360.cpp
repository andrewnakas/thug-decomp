extern "C" void func_001F5E60(void* p);

struct Obj_001F5360 {
    char pad[0x48];
    int m_sub;
    void Run();
};

void Obj_001F5360::Run()
{
    func_001F5E60(&m_sub);
}
