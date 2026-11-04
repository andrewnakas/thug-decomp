extern "C" void func_001180E8(void* p);

struct Obj00144DA0 {
    char pad[0x4];
    void* m_p;
    void Run();
};

void Obj00144DA0::Run()
{
    func_001180E8(m_p);
}
