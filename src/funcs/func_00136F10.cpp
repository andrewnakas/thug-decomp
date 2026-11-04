extern "C" void func_00134A98(void* p);

struct Obj00136F10 {
    char pad[0x20];
    void* m_p;
    void Run();
};

void Obj00136F10::Run()
{
    func_00134A98(m_p);
}
