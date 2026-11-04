extern "C" void func_001180B0(void* p);

struct Obj00144DD0 {
    char pad[0x4];
    void* m_p;
    void Run();
};

void Obj00144DD0::Run()
{
    func_001180B0(m_p);
}
