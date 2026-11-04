extern "C" void func_001876A8(void* p);

struct Obj00187440 {
    char pad[0x20];
    void* m_p;
    void Run();
};

void Obj00187440::Run()
{
    func_001876A8(m_p);
}
