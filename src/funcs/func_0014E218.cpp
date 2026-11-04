extern "C" void func_001708F8(void* p);

struct Obj0014E218 {
    char pad[0x20];
    void* m_p;
    void Run();
};

void Obj0014E218::Run()
{
    func_001708F8(m_p);
}
