extern "C" void func_00186E80(void* p);

struct Obj00187258 {
    char pad[0x20];
    void* m_p;
    void Run();
};

void Obj00187258::Run()
{
    func_00186E80(m_p);
}
